#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/async.h>
#include <spdlog/async_logger.h>

#include <iostream>

int main()
{
    // 设置全局的刷新策略
    // 每秒刷新
    spdlog::flush_every(std::chrono::seconds(1));
    // 遇到debug以上等级的日志立即刷新
    spdlog::flush_on(spdlog::level::level_enum::debug);
    // 设置全局的日志输出等级 -- 无所谓 --每个日志器可以独立进行设置
    spdlog::set_level(spdlog::level::level_enum::debug);

    // 创建同步日志器（标准输出/文件） -- 工厂接口默认创建的就是同步日志器
    auto logger = spdlog::stdout_color_mt("default-logger");
    // 创建文件日志器
    auto file_logger = spdlog::basic_logger_mt("file-logger", "logs/file.log");

    // 设置日志器的刷新策略，以及设置日志器的输出等级
    //  logger->flush_on(spdlog::level::level_enum::debug);
    //  logger->set_level(spdlog::level::level_enum::debug);

    // 设置日志输出格式
    logger->set_pattern("[%H:%M:%S][%t][%-7l - %v] ");
    file_logger->set_pattern("[%H:%M:%S][%t][%-7l - %v] ");

    // 进行同步日志输出
    logger->trace("你好！{}", "小明");
    logger->debug("你好！{}", "小明");
    logger->info("你好！{}", "小明");
    logger->warn("你好！{}", "小明");
    logger->error("你好！{}", "小明");
    logger->critical("你好！{}", "小明");

    // 进行同步文件日志输出
    file_logger->trace("你好！{}", "小明");
    file_logger->debug("你好！{}", "小明");
    file_logger->info("你好！{}", "小明");
    file_logger->warn("你好！{}", "小明");
    file_logger->error("你好！{}", "小明");
    file_logger->critical("你好！{}", "小明");

    // 初始化异步日志输出线程配置
    // 初始化线程池，队列大小为 3027，工作线程数量为 1;
    spdlog::init_thread_pool(3027,1);
    // 进行异步日志输出
    auto async_logger = spdlog::stdout_color_mt<spdlog::async_factory>("async_logger");
    async_logger->set_pattern("[%H:%M:%S][%t][%-7l - %v] ");

    auto async_file_logger = spdlog::basic_logger_mt<spdlog::async_factory>("async_file_logger", "logs/async_file.log");
    async_file_logger->set_pattern("[%H:%M:%S][%t][%-7l - %v] ");

    // 进行异步日志输出
    async_logger->trace("你好！{}", "小明");
    async_logger->debug("你好！{}", "小明");
    async_logger->info("你好！{}", "小明");
    async_logger->warn("你好！{}", "小明");
    async_logger->error("你好！{}", "小明");
    async_logger->critical("你好！{}", "小明");

    // 进行异步文件日志输出
    async_file_logger->trace("你好！{}", "小明");
    async_file_logger->debug("你好！{}", "小明");
    async_file_logger->info("你好！{}", "小明");
    async_file_logger->warn("你好！{}", "小明");
    async_file_logger->error("你好！{}", "小明");
    async_file_logger->critical("你好！{}", "小明");

    std::cout << "日志输出演示完毕！\n";

    return 0;
}