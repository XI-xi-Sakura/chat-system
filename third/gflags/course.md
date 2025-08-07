## gflags 使用

### 包含头文件
使用 gflags 库来定义/解析命令行参数必须包含如下头文件
```cpp
#include <gflags/gflags.h>
```

### 定义参数
利用 gflag 提供的宏定义来定义参数。该宏的 3 个参数分别为命令行参数名, 参数默认值, 参数的帮助信息。
```cpp
DEFINE_bool(reuse_addr, true, "是否开始网络地址重用选项");
DEFINE_int32(log_level, 1, "日志等级: 1-DEBUG, 2-WARN, 3-ERROR");
DEFINE_string(log_file, "stdout", "日志输出位置设置，默认为标准输出");
```

gflags 支持定义多种类型的宏函数:
```cpp
DEFINE_bool
DEFINE_int32
DEFINE_int64
DEFINE_uint64
DEFINE_double
DEFINE_string
```
### 访问参数
我们可以在程序中通过 `FLAGS_name`像正常变量一样访问标志参数。比如在上面的例子中，我们可以通过 `FLAGS_big_menu `和 `FLAGS_languages` 变量来访问命令行参数。

### 不同文件访问参数
如果想再另外一个文件访问当前文件的参数，以参数 `FLAGS_big_menu` 为例，我们可以使用用宏 `DECLARE_bool(big_menu)` 来声明引入这个参数。
其实这个宏就相当于做了 `extern FLAGS_big_menu`，定义外部链接属性。

### 初始化所有参数
当我们定义好参数后，需要告诉可执行程序去处理解析命令行传入的参数，使得 FLAGS_* 变量能得到正确赋值。我们需要在 main 函数中，调用下面的函数来解决命令行传入的所有参数。
```cpp
google::ParseCommandLineFlags(&argc, &argv, true);
```
- argc 和 argv 就是 main 的入口参数
- 第三个参数被称为 remove_flags。
  - 如果它为 true，表示 ParseCommandLineFlags 会从 argv 中移除标识和它们的参数，相应减少 argc 的值。
  - 如果它为 false ,ParseCommandLineFlags 会保留 argc 不变，但将会重新调整它们的顺序，使得标识再前面。

### 运行参数设置
gflags 为我们提供了多种命令行设置参数的方式。

string 和 int 设置参数
```shell
exec --log_file="./main.log"
exec --log_file="./main.log"
exec --log_file "./main.log"
exec --log_file "./main.log"
```

bool 设置参数
```shell
exec --reuse_addr
exec --noreuse_addr
exec --reuse_addr=true
exec --reuse_addr=false
```
-- 将会终止标识的处理。比如在 exec -f1 1 -- -f2 2 中，f1 被认为是一个标识，但 f2 不会

### 配置文件的使用
配置文件的使用，其实就是为了让程序的运行参数配置更加标准化，不需要每次运行的时候都手动收入每个参数的数值，而是通过配置文件，一次编写，永久使用。
需要注意的是，配置文件中选项名称必须与代码中定义的选项名称一致。
样例：
```cpp
-reuse_addr=true,
-log_level=3
-log_file=./log/main.log
```

### 特殊参数标识
gflags 也默认为我们提供了几个特殊的标识。
```shell
--help     # 显示文件中所有标识的帮助信息
--helpfull # 和--help 一样，帮助信息更全面一些
--helpshort # 只显示当前执行文件里的标志
--helpxml # 以 xml 方式打印，方便处理
--version # 打印版本信息，由 google::SetVersionString()设定
```
```shell
--flagfile  -flagfile=f # 从文件 f 中读取命令行参数
```

## 入门案例

样例编写：
编写样例代码：main.cc
```cpp
#include <gflags/gflags.h>
#include <iostream>

DEFINE_bool(reuse_addr, true, "是否开始网络地址重用选项");
DEFINE_int32(log_level, 1, "日志等级: 1-DEBUG, 2-WARN, 3-ERROR");
DEFINE_string(log_file, "stdout", "日志输出位置设置，默认为标准输出");

int main(int argc, char* argv[])
{
    google::ParseCommandLineFlags(&argc, &argv, true);
    std::cout << "reuse: " << FLAGS_reuse_addr << std::endl;
    std::cout << "reuse: " << FLAGS_log_level << std::endl;
    std::cout << "reuse: " << FLAGS_log_file << std::endl;
    return 0;
}
```

配置文件编写：main.conf
```cpp
-reuse_addr=true
-log_level=3
-log_file=./log/main.log
```

Makefile 编写：
```shell
main: main.cc
    g++ -std=c++17 $^ -o $@ -lgflags
```

### 样例运行：
运行代码：
```shell
dev@dev-host:~/workspace/gflags$ ./main --help
Flags from main.cc:
  -log_file: "日志输出位置设置，默认为标准输出" type: string default: "stdout"
  -log_level: "日志等级: 1-DEBUG, 2-WARN, 3-ERROR" type: int32 default: 1
  -reuse_addr: "是否开始网络地址重用选项" type: bool default: true
```

运行代码 2：
```shell
dev@dev-host:~/workspace/gflags$ ./main
reuse: 1
reuse: 1
reuse: stdout
```

运行代码 3：
```shell
dev@dev-host:~/workspace/gflags$ ./main --log_level=2 --log_file=./log/main.log
reuse: 1
reuse: 2
reuse: ./log/main.log
```

运行代码 4：
```shell
dev@dev-host:~/workspace/gflags$ ./main --flagfile=./main.conf
reuse: 1
reuse: 3
reuse: ./log/main.log
```