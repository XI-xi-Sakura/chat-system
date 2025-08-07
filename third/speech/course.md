### C++ sdk 安装
- 安装 sdk 所需依赖
```Shell
# 安装 jsoncpp
sudo apt install libjsoncpp - dev
# 安装 libcurl
sudo apt install curl
# 安装 openssl
# ubuntu 22.04 默认安装了
```
- 创建工程集成 C++ SDK

```
root@hcss - ecs - 2618: / home / zsc / test_aip# tree - L 1
├── aip - cpp - sdk - 4.16.6
├── main.cc
└── public
2 directories, 1 file
```
- aip - cpp - sdk - 4.16.6 为百度 C++ SDK 源码
- main.cc 为我们工程的代码，主要是通过 sdk 接口调用语音识别服务
- public 目录下为一些测试音频数据

### 接口描述
向远程服务上传整段语音进行识别

```cpp
void asr(aip::Speech client)
{
    // 无可选参数调用接口
    std::string file_content;
    aip::get_file_content("./assets/voice/16k_test.pcm", &file_content);
    Json::Value result = client.recognize(file_content, "pcm", 16000, aip::null);

    // 极速版调用函数
    // Json::Value result = client.recognize_pro(file_content, "pcm", 16000, aip::null);

    // 如果需要覆盖或者加入参数
    std::map<std::string, std::string> options;
    options["dev_pid"] = "1537";
    Json::Value result = client.recognize(file_content, "pcm", 16000, options);
}
```

接口函数说明:
| 参数   | 类型   | 描述                                                         | 是否必须 |
| ------ | ------ | ------------------------------------------------------------ | -------- |
| data   | byte[] | 语音二进制数据,语言文件的格式，pcm 或者 wav 或者 amr。不区分大小写 | 是       |
| format | String | 语音文件的格式，pcm 或者 wav 或者 amr。不区分大小写。推荐pcm文件 | 是       |
| rate   | int    | 采样率，16000，固定值                                        | 是       |
| cuid   | String | 用户唯一标识，用来区分用户，填写机器 MAC 地址或 IMEI 码，长度为60以内 | 否       |
| dev_pid| int    | 不填写可lan参数生效，都不填写，默认1537（普通话 输入法模型），dev_pid参数见下面的表格 | 否       |
| lm_id  | int    | 自训练平台模型id，填dev_pid = 8001 或 8002生效               | 选填     |

dev_pid 参数列表
| dev_pid | 语言             | 模型               | 是否有标点 | 备注           |
| ------- | ---------------- | ------------------ | ---------- | -------------- |
| 1537    | 普通话(纯中文识别) | 语音近场识别模型   | 有标点     | 支持自定义词库 |
| 1737    | 英语             | 英语模型           | 无标点     | 不支持自定义词库 |
| 1637    | 粤语             | 粤语模型           | 有标点     | 不支持自定义词库 |
| 1837    | 四川话           | 四川话模型         | 有标点     | 不支持自定义词库 |

返回数据参数详情
| 参数    | 类型 | 是否一定输出 | 描述                                                         |
| ------- | ---- | ------------ | ------------------------------------------------------------ |
| err_no  | int  | 是           | 错误码                                                       |
| err_msg | int  | 是           | 错误码描述                                                   |
| sn      | int  | 是           | 语音数据唯一标识，系统内部产生，用于 debug                   |
| result  | int  | 是           | 识别结果数组，提供1 - 5 个候选结果，string 类型为识别的字符串，utf - 8 编码 |

 

### 测试样例
```C++
#include "aip - cpp - sdk - 4.16.7/speech.h"

void ASR(aip::Speech* client) {
    std::map<std::string, std::string> options;
    //options["dev_pid"] = "1537"; // 普通话识别
    std::string file_content;
    aip::get_file_content("./16k.pcm", &file_content);
    Json::Value result = client->recognize(file_content, "pcm", 16000, options);
    std::cout << "语音识别本地文件结果:" << std::endl << result.toStyledString();

    if (result["err_no"].asInt() != 0) {
        std::cout << result["err_msg"].asString() << std::endl;
        return;
    }
    std::string message = result["result"][0].asString();
    std::cout << "message :" << message << std::endl;
}

int main() {
    // 务必替换百度云控制台中新建百度语音应用的 Api Key 和 Secret Key
    aip::Speech * client = new aip::Speech("app_id", "api_key", "secret_key");

    // 语音识别调用
    ASR(client);

    return 0;
}
```

编译运行代码：
```Shell
# g++ - o main main.cc - std = c++11 - lcurl - lcrypto - ljsoncpp
# ./main
语音识别本地文件结果:
{
    "corpus_no": "7356161115255294520",
    "err_msg": "success.",
    "err_no": 0,
    "result": [
        "\u5317\u4eac\u79d1\u6280\u9986\u3002"
    ],
    "sn": "622523813741712739727"
}
message :北京科技馆。
```

至此，百度语音识别 sdk 已经用起来了。

注意:
1. 关于参数：如果相关音频参数不符合要求，可以使用 ffmpeg 工具进行转码
    - 采样率：百度语音识别一般仅支持 16000 的采样率。即 1 秒采样 16000 次。
    - 位深：无损音频格式 pcm 和 wav 可以设置，百度语音识别使用 16bits 小端序，即 2 个字节记录 1/16000 s 的音频数据。
    - 声道：百度语音识别仅支持单声道。
2. 语音识别返回结果与音频内容不匹配，例如："嗨嗨嗨"、"嗯嗯嗯嗯嗯"、"什么" 等错误返回
    - 解决方法：排查音频采样率、声道、格式等参数是否符合接口规范。如与要求不符，需要用工具对音频进行转码。
3. 在使用之前一定先过一遍官方文档：https://ai.baidu.com/ai - doc/SPEECH/dlbxfrs5o

### 相关链接
- 测试音频下载链接: https://platform.bj.bcebos.com/sdk/asr/asr_doc/doc_download_files/public.zip
- C++ sdk 使用文档: https://ai.baidu.com/ai - doc/SPEECH/dlbxfrs5o
- 常见问题: https://ai.baidu.com/ai - doc/SPEECH/wlciqqafjo
- 音频格式及转码: https://ai.baidu.com/ai - doc/SPEECH/7k38lx pwf
- 调用示例: https://github.com/Baidu - AIP/sdk - demo 