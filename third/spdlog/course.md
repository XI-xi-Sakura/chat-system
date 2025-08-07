## 介绍

spdlog 是一个高性能、超快速、零配置的 C++ 日志库，它旨在提供简洁的 API 和丰富的功能，同时保持高性能的日志记录。它支持多输出目标、格式化选项、线程安全以及异步日志记录。以下是 spdlog 的详细介绍和使用方法。

github 链接：https://github.com/gabime/spdlog

### 特点
- 高性能：spdlog 专为速度而设计，即使在高负载情况下也能保持良好的性能。
- 零配置：无需复杂的配置，只需包含头文件即可在项目中使用。
- 异步日志：支持异步日志记录，减少对主线程的影响。
- 多输出：支持自定义日志消息的格式，包括时间戳、进程 ID、日志级别、线程 ID 等。
- 跨平台：跨平台兼容，支持 Windows、Linux、macOS 等操作系统。
- 丰富的 API：提供丰富的日志级别和操作符重载，方便记录各种类型的日志。

### 安装

命令安装：
```bash
# For Ubuntu or Debian
sudo apt-get install libspdlog - dev
# For CentOS or RHEL
sudo yum install spdlog - dev
```



### 使用

包含头文件：
在你的 C++ 源文件中包含 spdlog 的头文件：
```cpp
#include <spdlog/spdlog.h>
```
日志输出等级枚举
```cpp
namespace level {
    enum level_enum : int {
        trace = SPDLOG_LEVEL_TRACE,
        debug = SPDLOG_LEVEL_DEBUG,
        info = SPDLOG_LEVEL_INFO,
        warn = SPDLOG_LEVEL_WARN,
        err = SPDLOG_LEVEL_ERROR,
        critical = SPDLOG_LEVEL_CRITICAL,
        off = SPDLOG_LEVEL_OFF,
        // 自定义日志级别
        n_levels
    };
} // namespace level
```
日志输出格式自定义：
可以自定义日志消息的格式：
```cpp
logger->set_pattern("%Y-%m-%d %H:%M:%S [%t] [%l] %v");
```
格式说明：
- %Y：年份（Year）。
- %m：月份（Month）。
- %d：日期（Day）。
- %H：小时（24 - hour format）。
- %M：分钟（Minute）。
- %S：秒（Second）。
- %t：线程 ID（thread ID）。
- %l：日志级别名称（level name，如 INFO，DEBUG，ERROR 等）。
- %v：日志内容（message）。
- %n：日志器名称（Logger name）。  

日志记录器类：
创建一个基本的日志记录器，并设置日志级别和输出模式：
```cpp
namespace spdlog {
    class logger {
    public:
        logger(std::string name);

        /**
         * 构造一个新的日志记录器对象，并关联单个日志输出目标
         * 
         * name 日志记录器的名称
         * single_sink 单个日志输出目标的智能指针
         */
        logger(std::string name, sink_ptr single_sink);

        /**
         * 构造一个新的日志记录器对象，并关联多个日志输出目标
         * 
         * name 日志记录器的名称
         * sinks 多个日志输出目标的初始化列表
         */
        logger(std::string name, sinks_init_list sinks);

        /**
         * 设置日志记录器的日志级别
         * 
         * log_level 日志级别
         */
        void set_level(level::level_enum log_level);

        /**
         * 设置日志记录器的格式化器
         * 
         * f 格式化器的智能指针
         */
        void set_formatter(std::unique_ptr<formatter> f);

        /**
         * 记录对应级别的日志消息
         * 
         * fmt 格式化字符串
         * args 格式化参数
         */
        template<typename... Args>
        void trace(fmt::format_string<Args...> fmt, Args &&... args);
        template<typename... Args>
        void debug(fmt::format_string<Args...> fmt, Args &&... args);
        template<typename... Args>
        void info(fmt::format_string<Args...> fmt, Args &&... args);
        template<typename... Args>
        void warn(fmt::format_string<Args...> fmt, Args &&... args);
        template<typename... Args>
        void error(fmt::format_string<Args...> fmt, Args &&... args);
        template<typename... Args>
        void critical(fmt::format_string<Args...> fmt, Args &&... args);


        void flush(); // 刷新日志
        // 立即刷新指定级别的日志
        void flush_on(level::level_enum log_level);
        // 策略刷新 - 触发指定等级日志时，便立即刷新日志的输出
    };
}
```
异步日志记录类：
为了异步记录日志，可以使用 spdlog::async_logger：
```cpp
class async_logger final : public logger {
public:
    async_logger(std::string logger_name,
                 sinks_init_list sinks,
                 std::weak_ptr<details::thread_pool> tp,
                 async_overflow_policy overflow_policy = async_overflow_policy::block);
    async_logger(std::string logger_name,
                 sink_ptr single_sink,
                 std::weak_ptr<details::thread_pool> tp,
                 async_overflow_policy overflow_policy = async_overflow_policy::block);
    // 异步日志输出需要异步工作线程的支持，这里是线程池类
    class thread_pool {
    public:
        thread_pool(size_t q_max_items,
                    size_t threads_n,
                    std::function<void()> on_thread_start,
                    std::function<void()> on_thread_stop);
        thread_pool(size_t q_max_items, size_t threads_n);
        thread_pool(size_t q_max_items, size_t threads_n,
                    const std::function<void()> &on_thread_start,
                    const std::function<void()> &on_thread_stop);
    };
};
std::shared_ptr<spdlog::details::thread_pool> thread_pool() {
    static auto tp = std::make_shared<spdlog::details::thread_pool>(8192, 1);
    return tp;
}
// 默认线程池的初始化接口
inline void init_thread_pool(size_t q_size, size_t thread_count) {
    auto tp = std::make_shared<spdlog::details::thread_pool>(q_size, thread_count);
    spdlog::details::registry::instance().set_tp(tp);
}
auto async_logger = spdlog::async_logger_mt("async_logger",
                                            async_sink,
                                            thread_pool());
async_logger->info("This is an asynchronous info message");
```
日志记录器工厂类：
```cpp
C++
using async_factory = async_factory_impl<async_overflow_policy::block>;


template<typename Sink, typename... SinkArgs>
inline std::shared_ptr<spdlog::logger> create_async(
    std::string logger_name,
    SinkArgs &&... sink_args)

//创建一个彩色输出到标准输出的日志记录器，默认工厂创建同步日志记录器
template<typename Factory = spdlog::synchronous_factory>
std::shared_ptr<logger> stdout_color_mt(
    const std::string &logger_name,
    color_mode mode = color_mode::automatic);
//标准错误
template<typename Factory = spdlog::synchronous_factory>
std::shared_ptr<logger> stderr_color_mt(
    const std::string &logger_name,
    color_mode mode = color_mode::automatic);
//指定文件
template<typename Factory = spdlog::synchronous_factory>
std::shared_ptr<logger> basic_logger_mt(
    const std::string &logger_name,
    const filename_t &filename,
    bool truncate = false,
    const file_event_handlers &event_handlers = {})
//循环文件
template<typename Factory = spdlog::synchronous_factory>
std::shared_ptr<logger> rotating_logger_mt(
    const std::string &logger_name,
    const filename_t &filename,
    size_t max_file_size,
    size_t max_files,
    bool rotate_on_open = false)
...

日志落地类
```
日志落地类
```cpp
namespace spdlog {
namespace sinks {
    class SPDLOG_API sink
    {
    public:
        virtual ~sink() = default;
        virtual void log(const details::log_msg &msg) = 0;


        virtual void flush() = 0;
        virtual void set_pattern(const std::string &pattern) = 0;
        virtual void set_formatter(std::unique_ptr<spdlog::formatter> sink_formatter) = 0;

        void set_level(level::level_enum log_level);
    };

    using stdout_sink_mt;
    using stderr_sink_mt;
    using stdout_color_sink_mt;
    using stderr_color_sink_mt;
    // 滚动日志文件 - 超过一定大小则自动重新创建新的日志文件
    sink_ptr rotating_file_sink(filename_t base_filename,
                                std::size_t max_size,
                                std::size_t max_files,
                                bool rotate_on_open = false,
                                const file_event_handlers &event_handlers = {});
    using rotating_file_sink_mt = rotating_file_sink<std::mutex>;
    // 普通的文件落地
    sink_ptr basic_file_sink(const filename_t &filename,
                             bool truncate = false,
                             const file_event_handlers &event_handlers = {});
    using basic_file_sink_mt = basic_file_sink<std::mutex>;

    using kafka_sink_mt = kafka_sink<std::mutex>;
    using mongo_sink_mt = mongo_sink<std::mutex>;
    using tcp_sink_mt = tcp_sink<std::mutex>;
    using udp_sink_mt = udp_sink<std::mutex>;
    //...（省略的其他可能代码）
    // /*_st: 单线程版本，不用加锁，效率更高。
    // /*_mt: 多线程版本，用于多线程程序是线程安全的。
}
}
```
全局接口：
```cpp
// 输出等级设置接口
void set_level(level::level_enum log_level);
// 日志刷新策略，每隔（rd）刷新一次
void flush_every(std::chrono::seconds interval);
// 日志刷新策略，触发等级（level）则刷新
void flush_on(level::level_enum log_level);
```
记录日志：
使用日志记录器记录不同级别的日志：
```cpp
logger->trace("This is a trace message");
logger->debug("This is a debug message");
logger->info("This is an info message");
logger->warn("This is a warning message");
logger->error("This is an error message");
logger->critical("This is a critical message");
```
使用示例
```cpp
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/async.h>
#include <spdlog/async_logger.h>
void multi_sink_example()
{
    // 创建一个标准输出的 sink 对象
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_pattern("[%^%l%$] %v");
    // 创建一个文件输出的 sink 对象
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/multisink.txt", true);
    file_sink->set_level(spdlog::level::trace);
    // 创建一个日志对象，用于输出日志
    spdlog::logger logger("multi_sink", {console_sink, file_sink});
    logger.set_level(spdlog::level::debug);
    // 每个 sink 都可以设置初步过滤等级，其次，内部每个 sink 也可以设置自己独立的过滤等级
    logger.warn("This will appear in both console and file");
    logger.info("This will appear in both console and file");
    logger.debug("This will appear only in the file");
}
void async_example()
{
    // 初始化线程池，3728 为队列大小，1 为线程数，线程数属性是可设置
    spdlog::init_thread_pool(3728, 1);
    // 通过工厂模式创建异步日志记录器的同时，会在内部创建默认线程池作为异步通道
    auto async_factory = spdlog::create_async_nb<spdlog::sinks::stdout_color_sink_mt>("async_logger");
    async_factory->set_pattern("[%Y-%m-%d %H:%M:%S] [%t] [%l] %v");
    // 要注意的是，在多参数的时候，spdlog 并非使用 %d 这种通配符来匹配参数，而是用多参数的方式来匹配，所以要注意使用方式
    for (int i = 0; i < 10; ++i)
    {
        async_factory->info("Async message #{}", i, "hello");
    }
}
int main()
{
    multi_sink_example();
    async_example();
    return 0;
}
```
编译命令：
```c++
main : main.cc 
    g++ -std=c++17 $^ -o $@ -lspdlog -lfmt -pthread
```
二次封装：
因为 spdlog 的日志对象对文件名和行号并不是很友好（也有可能进行调试获取...），以及因为 spdlog 本身实现了线程安全，但是使用默认日志器每次进行单例获取，效率会有降低，因此进行二次封装，方便使用。

```cpp
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/async.h>
namespace inc {
    static std::shared_ptr<spdlog::logger> g_logger;
    void init_stdout_logger(const std::string &logger_name,
                            spdlog::level::level_enum logger_level) {
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        console_sink->set_level(logger_level);
        console_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%t] [%l] %v");
        g_logger = std::make_shared<spdlog::logger>(logger_name, console_sink);
        g_logger->set_level(logger_level);
    }
    void init_file_logger(const std::string &logger_name,
                          const std::string &file_name,
                          spdlog::level::level_enum logger_level) {
        auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(file_name, true);
        file_sink->set_level(logger_level);
        file_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%t] [%l] %v");
        g_logger = std::make_shared<spdlog::logger>(logger_name, file_sink);
        g_logger->set_level(logger_level);
    }
    void init_async_logger(const std::string &logger_name,
                           const std::string &file_name,
                           spdlog::level::level_enum logger_level) {
        spdlog::init_thread_pool(3728, 1);
        auto async_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(file_name, true);
        async_sink->set_level(logger_level);
        async_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%t] [%l] %v");
        g_logger = spdlog::create_async_nb<spdlog::sinks::basic_file_sink_mt>(logger_name, async_sink);
        g_logger->set_level(logger_level);
    }
#define INC_LOG_TRACE(...) ::inc::g_logger->trace(__VA_ARGS__)
#define INC_LOG_DEBUG(...) ::inc::g_logger->debug(__VA_ARGS__)
#define INC_LOG_INFO(...) ::inc::g_logger->info(__VA_ARGS__)
#define INC_LOG_WARN(...) ::inc::g_logger->warn(__VA_ARGS__)
#define INC_LOG_ERROR(...) ::inc::g_logger->error(__VA_ARGS__)
#define INC_LOG_CRITICAL(...) ::inc::g_logger->critical(__VA_ARGS__)
}
```
