#include <etcd/Client.hpp>
#include <etcd/Watcher.hpp>
void watcherCallback(etcd::Response const &resp)
{
    if (resp.error_code() != 0)
    {
        std::cout << "Watcher Error: " << resp.error_code();
        std::cout << " - " << resp.error_message() << std::endl;
    }
    else
    {
        for (auto const &ev : resp.events())
        {
            if (ev.event_type() == etcd::Event::EventType::PUT)
            {
                // 如果是新增值，则通过当前值来看新增的是什么值
                std::cout << "服务 " << ev.kv().key() << " 新增主机：";
                std::cout << ev.kv().as_string() << std::endl;
            }
            else if (ev.event_type() == etcd::Event::EventType::DELETE_)
            {
                // 如果是值被删除，则需要通过发生事件之前的值来了解哪个值被删除了
                std::cout << "服务 " << ev.kv().key() << " 下线主机：";
                std::cout << ev.prev_kv().as_string() << std::endl;
            }
        }
    }
}

int main()
{
    std::string registry_host = "http://127.0.0.1:2379";
    std::string service_key = "/service/user/instance";
    etcd::Client etcd(registry_host);
    // 初次使用 ls 获取能够提供指定服务的实例信息
    etcd::Response resp = etcd.ls(service_key).get();
    if (resp.is_ok())
    {
        for (std::size_t i = 0; i < resp.keys().size(); ++i)
        {
            std::cout << " - " << resp.key(i) << " : " << resp.value(i).as_string() << std::endl;
        }
    }
    else
    {
        std::cout << "Get Service Error: " << resp.error_code();
        std::cout << " - " << resp.error_message() << std::endl;
    }
    // 获取之后，然后定义监控对象，监控目录内容变化，通过目录变化来感知服务的上线与下线
    etcd::Watcher watcher(registry_host, service_key, watcherCallback, true);
    watcher.Wait();
    watcher.Cancel();

    return 0;
}