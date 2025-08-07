## 安装

### 安装依赖

```
sudo apt-get install -y git g++ make libssl-dev libprotobuf-dev libprotoc-dev protobuf-compiler libleveldb-dev
```

### 安装 brpc

```
git clone https://github.com/apache/brpc.git
cd brpc/
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr .. && cmake --build . -j6
make && sudo make install
```

## 类与接口介绍

### 日志输出类与接口
包含头文件: `#include <butil/logging.h>`
日志输出这里，本质上我们其实用不着 brpc 的日志输出，因此在这里主要介绍如何关闭日志输出。

```cpp
namespace logging {
enum LoggingDestination {
    LOG_TO_NONE = 0
};
struct BUTIL_EXPORT LoggingSettings {
    LoggingSettings();
    LoggingDestination logging_dest;
};
bool InitLogging(const LoggingSettings& settings);
}
```

### protobuf 类与接口

```cpp
namespace google {
namespace protobuf {
    /**
     * 一个抽象基类，用于表示可调用的回调对象。
     * 
     * Closure 类定义了一个接口，任何实现了该接口的类都可以作为回调对象使用。
     * 通常在异步操作完成时调用这个回调对象。
     */
    class PROTOBUF_EXPORT Closure {
    public:
        // 默认构造函数
        Closure() {}

        // 虚析构函数，确保派生类对象能被正确销毁
        virtual ~Closure();

        // 纯虚函数，派生类必须实现该函数，用于执行回调操作
        virtual void Run() = 0;
    };

    /**
     * 创建一个新的 Closure 回调对象。
     * 
     * 该函数接受一个无参数无返回值的函数指针，返回一个指向 Closure 对象的指针。
     * 当调用这个 Closure 对象的 Run() 方法时，会执行传入的函数。
     * 
     * function 无参数无返回值的函数指针。
     * Closure* 指向新创建的 Closure 对象的指针。
     */
    inline Closure* NewCallback(void (*function)());

    /**
     * 用于控制 RPC 调用的类，提供错误处理相关的功能。
     * 
     * RpcController 类提供了在 RPC 调用过程中检查错误状态和获取错误信息的方法。
     */
    class PROTOBUF_EXPORT RpcController {
        // 检查 RPC 调用是否失败
        bool Failed();

        // 获取 RPC 调用失败时的错误文本信息
        std::string ErrorText();
    }
}
}
```

### 服务端类与接口
这里只介绍主要用到的成员与接口。

```cpp
namespace brpc {
    /**
     * 服务器选项配置结构体，用于设置服务器运行时的相关参数。
     */
    struct ServerOptions {
        // 若连接在指定时间内无数据传输，则关闭该连接。默认值 -1 表示不启用此功能
        int idle_timeout_sec; // Default: -1 (disabled)
        // 服务器启动的线程数量，默认值为 CPU 核心数
        int num_threads; // Default: #cpu-cores
        //.....
    };

    /**
     * 服务所有权枚举，用于指定服务器对添加的服务对象的所有权。
     */
    enum ServiceOwnership {
        // 添加服务失败时，服务器将负责删除服务对象
        SERVER_OWNS_SERVICE,
        // 添加服务失败时，服务器也不会删除服务对象
        SERVER_DOESNT_OWN_SERVICE
    };

    /**
     * @brief 表示一个 BRPC 服务器类，提供启动、停止服务以及管理服务的功能。
     */
    class Server {
    public:
        /**
         * 向服务器添加一个 Protobuf 服务。
         * 
         * service 指向要添加的 Protobuf 服务对象的指针。
         * ownership 服务所有权，指定服务器对服务对象的管理方式。
         * int 成功返回 0，失败返回非 0 值。
         */
        int AddService(google::protobuf::Service* service,
                       ServiceOwnership ownership);

        /**
         * 启动服务器监听指定端口。
         * 
         * port 服务器监听的端口号。
         * opt 服务器选项配置指针，可为 NULL 使用默认配置。
         * int 成功返回 0，失败返回非 0 值。
         */
        int Start(int port, const ServerOptions* opt);

        /**
         * 停止服务器运行。
         * 
         * closewait_ms 关闭等待时间（毫秒），此参数已不再使用。
         * int 成功返回 0，失败返回非 0 值。
         */
        int Stop(int closewait_ms/*not used anymore*/);

        /**
         * 等待服务器停止运行，阻塞当前线程直到服务器完全停止。
         * 
         * int 成功返回 0，失败返回非 0 值。
         */
        int Join();

        /**
         * 阻塞当前线程，直到用户按下 Ctrl+C，或者调用 Stop 和 Join 方法停止服务器。
         */
        void RunUntilAskedToQuit();
    };

    /**
     * 闭包守卫类，用于自动管理 Protobuf 闭包对象的生命周期。
     * 
     * 在对象析构时，若闭包对象不为空，则自动调用其 Run 方法。
     */
    class ClosureGuard {
    public:
        /**
         * 构造函数，接收一个 Protobuf 闭包对象指针。
         * 
         * done 指向 Protobuf 闭包对象的指针。
         */
        explicit ClosureGuard(google::protobuf::Closure* done);

        /**
         *  析构函数，若闭包对象不为空，则调用其 Run 方法。
         */
        ~ClosureGuard() { if (_done) _done->Run(); }
    };

    /**
     * HTTP 头部信息类，用于管理 HTTP 请求和响应的头部信息。
     */
    class HttpHeader {
    public:
        /**
         * 设置 HTTP 内容类型。
         * 
         * type 要设置的内容类型字符串。
         */
        void set_content_type(const std::string& type);

        /**
         * 获取指定键的 HTTP 头部值。
         * 
         * key 要查找的头部键。
         * std::string* 指向头部值的指针，若未找到则返回 NULL。
         */
        const std::string* GetHeader(const std::string& key);

        /**
         * 设置指定键的 HTTP 头部值。
         * 
         * key 要设置的头部键。
         * value 要设置的头部值。
         */
        void SetHeader(const std::string& key,
                       const std::string& value);

        /**
         * 获取 HTTP 请求的 URI。
         * 
         * const URI& 引用返回 HTTP 请求的 URI 对象。
         */
        const URI& uri() const { return _uri; }

        /**
         * 获取 HTTP 请求的方法。
         * 
         * HttpMethod 返回 HTTP 请求的方法类型。
         */
        HttpMethod method() const { return _method; }

        /**
         * 设置 HTTP 请求的方法。
         * 
         * method 要设置的 HTTP 请求方法类型。
         */
        void set_method(const HttpMethod method);

        /**
         * 获取 HTTP 响应的状态码。
         * 
         * int 返回 HTTP 响应的状态码。
         */
        int status_code();

        /**
         * 设置 HTTP 响应的状态码。
         * 
         * status_code 要设置的 HTTP 响应状态码。
         */
        void set_status_code(int status_code);
    };

    /**
     * 控制器类，继承自 Protobuf 的 RpcController，用于控制 RPC 调用。
     */
    class Controller : public google::protobuf::RpcController {
    public:
        /**
         * 设置 RPC 请求的超时时间。
         * 
         * timeout_ms 超时时间，单位为毫秒。
         */
        void set_timeout_ms(int64_t timeout_ms);

        /**
         * 设置 RPC 请求的最大重试次数。
         * 
         * max_retry 最大重试次数。
         */
        void set_max_retry(int max_retry);

        /**
         * 获取 RPC 响应消息对象。
         * 
         * google::protobuf::Message* 指向响应消息对象的指针。
         */
        google::protobuf::Message* response();

        /**
         * 获取 HTTP 响应头部信息对象。
         * 
         * HttpHeader& 引用返回 HTTP 响应头部信息对象。
         */
        HttpHeader& http_response();

        /**
         * 获取 HTTP 请求头部信息对象。
         * 
         * HttpHeader& 引用返回 HTTP 请求头部信息对象。
         */
        HttpHeader& http_request();

        /**
         * 检查 RPC 调用是否失败。
         * 
         * bool 若调用失败返回 true，否则返回 false。
         */
        bool Failed();

        /**
         * 获取 RPC 调用失败时的错误文本信息。
         * 
         * std::string 错误文本信息。
         */
        std::string ErrorText();

        /**
         * 定义 RPC 响应后的回调函数类型。
         */
        using AfterRpcRespFnType = std::function<
            void(Controller* cntl,
                 const google::protobuf::Message* req,
                 const google::protobuf::Message* res)>;

        /**
         * 设置 RPC 响应后的回调函数。
         * 
         * fn 要设置的回调函数。
         */
        void set_after_rpc_resp_fn(AfterRpcRespFnType&& fn);
    };
}
```

客户端类与接口：

```cpp
namespace brpc {
struct ChannelOptions {
    //请求连接超时时间
    int32_t connect_timeout_ms;// Default: 200 (milliseconds)
    //rpc 请求超时时间
    int32_t timeout_ms;// Default: 500 (milliseconds)
    //最大重试次数
    int max_retry;// Default: 3
    //序列化协议类型
    AdaptiveProtocolType protocol = "baidu_std";
    //.....
}
class Channel : public ChannelBase {
    //初始化接口，成功返回 0;
    int Init(const char* server_addr_and_port,
             const ChannelOptions* options);
```

## 使用
### 同步调用

同步调用是指客户端会阻塞收到 server 端的响应或发生错误。
下面我们以 Echo（输出 hello world）方法为例，来讲解基础的同步 RPC 请求是如何实现的。

- 创建 proto 文件 - main.proto

```protobuf
// 定义协议的包名，用于避免命名冲突
package example;

// 开启 C++ 通用服务支持，这样可以使用通用的服务接口框架
option cc_generic_services = true;

// 定义 Echo 方法请求参数结构
// 该消息类型包含一个字符串字段，用于传递需要回声的消息
message EchoRequest {
    // 要进行回声处理的消息内容
    string message = 1;
};

// 定义 Echo 方法响应参数结构
// 该消息类型包含一个字符串字段，用于返回回声后的消息
message EchoResponse {
    // 回声处理后的消息内容
    string message = 1;
};

// 定义 RPC 远端方法
// 此服务提供了一个名为 Echo 的远程过程调用方法
service EchoService {
    // 定义 Echo 方法，接收一个 EchoRequest 类型的请求
    // 并返回一个 EchoResponse 类型的响应
    rpc Echo(EchoRequest) returns (EchoResponse);
};
```

- 创建服务端源码 - brpc_server.cpp

```cpp
#include <gflags/gflags.h>
#include <butil/logging.h>
#include <brpc/server.h>
#include <json2pb/pb_to_json.h>
#include "main.pb.h"

// 使用 gflags 定义一些命令行参数
DEFINE_int32(listen_port, 8000, "服务器地址信息");
DEFINE_int32(idle_timeout_s, -1, "空闲连接超时关闭时间：默认 -1 表示不关闭");
DEFINE_int32(thread_count, 3, "服务器启动线程数量");

namespace example {
class EchoServiceImpl : public EchoService {
public:
    EchoServiceImpl() {}
    virtual ~EchoServiceImpl() {}
    // cntl_base：包含除了 request 和 response 之外的参数集合
    // request：请求，只读的，来自 client 端的数据包
    // response：回复。需要用户填充，如果存在 required 字段没有被设置，该次调用会失败。
    // done：done 由框架创建，递给服务回调，包含了调用服务回调后的后续动作，包括检查 response 正确性，序列化，打包，发送逻辑。不管成功失败，done->Run() 必须在请求处理完成后被用户调用一次。
    virtual void Echo(google::protobuf::RpcController* cntl_base,
                      const EchoRequest* request,
                      EchoResponse* response,
                      google::protobuf::Closure* done) {
        // 类型于守卫锁，以 ARII 方式自动释放 done 对象
        brpc::ClosureGuard done_guard(done);

        brpc::Controller* cntl =
            static_cast<brpc::Controller*>(cntl_base);

        // 可选项：本质是设置一个 hook 函数，在发送响应后及在 cntl_base、request、response 释放之前调用
        cntl->set_after_rpc_resp_fn(std::bind(&EchoServiceImpl::CallAfterRpc,
                                              std::placeholders::_1, std::placeholders::_2,
                                              std::placeholders::_3));

        // 打印一些相关的参数日志信息
        std::cout << "请求内容：" << request->message() << std::endl;

        // 填充响应，客户端发送什么数据，服务器就回复什么数据
        response->set_message(request->message() + " Hello");
    }

    // 可选项： 回调函数， 此时响应已经发回给客户端，但是相关结构还没释放
    static void CallAfterRpc(brpc::Controller* cntl,
                             const google::protobuf::Message* req,
                             const google::protobuf::Message* res) {
        std::string req_str;
        std::string res_str;
        json2pb::ProtoMessageToJson(*req, &req_str, NULL);
        json2pb::ProtoMessageToJson(*res, &res_str, NULL);
        std::cout << "req: " << req_str << std::endl;
        std::cout << "res: " << res_str << std::endl;
    }
}; // namespace example
}  // namespace example

int main(int argc, char* argv[]) {
    logging::LoggingSettings log_setting;
    log_setting.logging_dest = logging::LoggingDestination::LOG_TO_NONE;
    logging::InitLogging(log_setting);
    // 解析命令行参数
    google::ParseCommandLineFlags(&argc, &argv, true);

    // 定义服务器
    brpc::Server server;

    // 创建服务对象．
    example::EchoServiceImpl echo_service_impl;

    // 将服务添加到服务器中
    if (server.AddService(&echo_service_impl,
                          brpc::SERVER_DOESNT_OWN_SERVICE) != 0) {
        std::cout << "add service failed!\n";
        return -1;
    }

    // 开始运行服务器
    brpc::ServerOptions options;
    options.idle_timeout_sec = FLAGS_idle_timeout_s;
    options.num_threads = FLAGS_thread_count;
    if (server.Start(FLAGS_listen_port, &options) != 0) {
        std::cout << "Fail to start EchoServer";
        return -1;
    }

    // 阻塞等待服务端运行
    server.RunUntilAskedToQuit();
    return 0;
}
```

- 创建客户端源码 - client.cpp

```cpp
#include <gflags/gflags.h>
#include <butil/logging.h>
#include <butil/time.h>
#include <brpc/channel.h>
#include "main.pb.h"

DEFINE_string(protocol, "baidu_std", "通信协议类型，默认使用 brpc 自定协议");
DEFINE_string(server_host, "127.0.0.1:8000", "服务器地址信息");
DEFINE_int32(timeout_ms, 500, "Rpc 请求超时时间 - 毫秒");
DEFINE_int32(max_retry, 3, "请求重试次数");

int main(int argc, char* argv[]) {
    // 解析命令参数
    google::ParseCommandLineFlags(&argc, &argv, true);

    // 创建通道，可以理解为客户端到服务器的一条通信线路
    brpc::Channel channel;

    // 初始化通道，NULL 表示使用默认选项
    brpc::ChannelOptions options;
    options.protocol = FLAGS_protocol;
    options.timeout_ms = FLAGS_timeout_ms;
    options.max_retry = FLAGS_max_retry;
    if (channel.Init(FLAGS_server_host.c_str(), &options) != 0) {
        LOG(ERROR) << "Fail to initialize channel";
        return -1;
    }

    // 通常，我们不应直接调用通道，而是包装它的 stub 服务，通过 stub 进行 rpc 调用
    example::EchoService_Stub stub(&channel);

    // 创建请求、响应、控制对象
    example::EchoRequest request;
    example::EchoResponse response;
    brpc::Controller cntl;

    // 构造请求响应
    request.set_message("hello world");

    // 由于“done”（最后一个参数）为 NULL，表示阻塞等待响应
    stub.Echo(&cntl, &request, &response, NULL);
    if (cntl.Failed()) {
        std::cout << "请求失败：" << cntl.ErrorText() << std::endl;
        return -1;
    }
    std::cout << "响应：" << response.message() << std::endl;
    return 0;
}
```

- 编写 Makefile

参考 example 的例子，修改一下 BRPC_PATH 即可。

```makefile
all: brpc_server brpc_client

brpc_server: brpc_server.cc main.pb.cc
    g++ -std=c++17 $^ -o $@ -lbrpc -lleveldb -lgflags -lssl -lcrypto -lprotobuf

brpc_client: brpc_client.cc main.pb.cc
    g++ -std=c++17 $^ -o $@ -lbrpc -lleveldb -lgflags -lssl -lcrypto -lprotobuf

%.proto.cc: %.proto
    protoc --cpp_out=. $<
```

### 异步调用

异步调用是指客户端注册一个响应处理回调函数，当调用一个 RPC 接口时立即返回，不会阻塞等待响应，当 server 端返回响应时会调用传入的回调函数处理响应。

具体的做法：给 CallMethod 传递一个额外的回调对象 done，CallMethod 在发出 request 后就结束了，而不是在 RPC 结束后。当 server 端返回 response 或发生错误（包括超时）时，done->Run() 会被调用。对 RPC 的后续处理应该写在 done->Run() 里，而不是 CallMethod 后。由于 CallMethod 结束不意味着 RPC 结束，response/controller 仍可能被框架及 done->Run() 使用，它们一般得创建在堆上，并在 done->Run() 中删除。如果提前删除了它们，那当 done->Run() 被调用时，将访问到无效内存。

下面是异步调用的伪代码：

```cpp
static void OnRPCDone(MyResponse* response, brpc::Controller* cntl) {
    // unique_ptr 会帮助我们在 return 时自动删掉 response/cntl，防止忘记。gcc 3.4 下的 unique_ptr 是模拟版本。
    std::unique_ptr<MyResponse> response_guard(response);
    std::unique_ptr<brpc::Controller> cntl_guard(cntl);
    if (cntl->Failed()) {
        // RPC 失败了，response 里的值是未定义的，勿用。
    } else {
        // RPC 成功了，response 里有我们想要的数据。开始 RPC 的后续处理。
    }
    // NewCallback 产生的 Closure 会在 Run 结束后删除自己，不用我们做。
}

MyResponse* response = new MyResponse;
brpc::Controller* cntl = new brpc::Controller;
MyService_Stub stub(&channel);

MyRequest request; // 不用 new request
request.set_foo(...); cntl->set_timeout_ms(...);
stub.some_method(cntl, &request, response,
                 brpc::NewCallback(OnRPCDone, response, cntl));
```

`sofa-brpc`

（此处为代码编译报错的截图内容，因截图文字较多且为报错信息，大致是编译 sofa-brpc 相关代码时出现的错误，如 `GOOGLE_ATTRIBUTE_DEPRECATED` 相关类型未定义、`boost::asio::ip::tcp::acceptor` 相关成员访问错误等 ，具体如下 ）

```
src/sofa/pbrpc/compressed_stream.cc: In file included from src/sofa/pbrpc/compressed_stream.cc:18:
src/sofa/pbrpc/gzip_stream.h:160:21: error: expected '}' at end of member declaration
  160 |     int buffer_size = -1 GOOGLE_ATTRIBUTE_DEPRECATED;
      |                     ^
src/sofa/pbrpc/gzip_stream.h:160:21: note: to match this '{'
src/sofa/pbrpc/gzip_stream.h:160:29: error: 'GOOGLE_ATTRIBUTE_DEPRECATED' does not name a type; did you mean 'GOOGLE_ATTRIBUTE_COLD'?
  160 |     int buffer_size = -1 GOOGLE_ATTRIBUTE_DEPRECATED;
      |                             ^~~~~~~~~~~~~~~~~~~~~~~~~
      |                             GOOGLE_ATTRIBUTE_COLD
src/sofa/pbrpc/gzip_stream.h:160:29: error: expected ';' at end of member declaration
  160 |     int buffer_size = -1 GOOGLE_ATTRIBUTE_DEPRECATED;
      |                             ^
      |                             ;
make[2]: *** [CMakeFiles/sofa_pbrpc.dir/build.make:117: CMakeFiles/sofa_pbrpc.dir/src/sofa/pbrpc/compressed_stream.cc.o] Error 1
src/sofa/pbrpc/rpc_listener.h:109:35: error: 'boost::asio::ip::tcp::acceptor' {aka 'class boost::asio::basic_socket_acceptor<boost::asio::ip::tcp>'} has no member named 'native'
  109 |         int ret = fcntl(_acceptor.native(), F_SETFD, FD_CLOEXEC);
      |                                   ^~~~~~
src/sofa/pbrpc/rpc_listener.h:110:41: error: 'boost::asio::ip::tcp::acceptor' {aka 'class boost::asio::basic_socket_acceptor<boost::asio::ip::tcp>'} has no member named 'native'
  110 |         fcntl(_acceptor.native(), F_GETFD) | FD_CLOEXEC);
      |                                         ^~~~~~
src/sofa/pbrpc/rpc_listener.h: In member function 'void sofa::pbrpc::RpcListener::async_accept()':
```

`srpc`

```shell
git clone --recursive https://github.com/sogou/srpc.git
cd srpc
make
make install

# 编译示例
cd tutorial
make
```



```
-- Installing: /usr/local/include/srpc/lz4.h
-- Installing: /usr/local/include/srpc/lz4frame.h
-- Installing: /usr/local/share/doc/srpc-0.10.2/README.md
-- Installing: /usr/local/lib/libsrpc.a
-- Installing: /usr/local/lib/libsrpc.so.0.10.2
-- Installing: /usr/local/lib/libsrpc.so.0
-- Installing: /usr/local/lib/libsrpc.so
-- Installing: /usr/local/bin/srpc_generator
make[1]: Leaving directory '/home/zsc/srpc/build.cmake'
```

## 封装思想
rpc 调用这里的封装，因为不同的服务调用使用的是不同的 Stub，这个封装起来的意义不大，因此我们只需要封装通信所需的 Channel 管理即可，这样当需要进行什么样的服务调用的时候，只需要通过服务名称获取对应的 channel，然后实例化 Stub 进行调用即可。

- 封装 Channel 的管理，每个不同的服务可能都会有多个主机提供服务，因此一个服务可能会对应多个 Channel，需要将其管理起来，并提供获取指定服务 channel 的接口
  - 进行 rpc 调用时，获取 channel，目前以 RR 轮转的策略选择 channel
- 提供进行服务声明的接口，因为在整个系统中，提供的服务有很多，但是当前可能并不一定会用到所有的服务，因此通过声明来告诉模块哪些服务是自己关心的，需要建立连接管理起来，没有添加声明的服务即使上线也不需要进行连接的建立。
- 提供服务上线时的处理接口，也就是新增一个指定服务的 channel
- 提供服务下线时的处理接口，也就是删除指定服务下的指定 channel