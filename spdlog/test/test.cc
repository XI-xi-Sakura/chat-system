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