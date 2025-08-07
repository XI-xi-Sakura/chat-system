#include <etcd/Client.hpp>
#include <etcd/Response.hpp>
#include <etcd/KeepAlive.hpp>
#include <etcd/Value.hpp>
#include <etcd/Watcher.hpp>
#include <thread>

void callback(etcd::Response &response)
{
    if (!response.is_ok())
    {
        std::cout << "get failed, error: " << response.error_message() << std::endl;
        return;
    }

    for (auto const &ev : response.events())
    {
        if (ev.event_type() == etcd::Event::EventType::PUT)
        {
            std::cout << "数据发生修改" << std::endl;
            std::cout << "原先数据:" << ev.prev_kv().key() << ":" << ev.prev_kv().as_string() << std::endl;
            std::cout << "新数据:" << ev.kv().key() << ":" << ev.kv().as_string() << std::endl;
        }
        else if (ev.event_type() == etcd::Event::EventType::DELETE_)
        {
            std::cout << "数据发生删除" << std::endl;
            std::cout << "删除数据:" << ev.prev_kv().key() << ":" << ev.prev_kv().as_string() << std::endl;
        }
    }
}

int main(int argc, char *argv[])
{
    std::string etcd_host = "127.0.0.1:2379";
    // 实例化客户端对象
    etcd::Client client(etcd_host);
    // 获取指定键值对信息
    auto response = client.ls("/server").get();
    if (!response.is_ok())
    {
        std::cout << "get failed, error: " << response.error_message() << std::endl;
        return -1;
    }
    // CHECK(0 == etcd.ls("/test/new_dir").get().keys().size());
    for (int i = 0; i < response.value().key().size(); i++)
    {
        // CHECK(resp.values()[0].as_string() == "value1");
        // response.values()：
        // 返回一个 std::vector<etcd::Value> 类型的向量，该向量包含了 etcd 响应中的所有值对象。
        std::cout << response.values()[i].key() << ":" << response.values()[i].as_string() << std::endl;

        // CHECK("/test/new_dir/key1" == resp.key(0));
        // CHECK("value1" == resp.value(0).as_string());
        std::cout << response.key(i) << ":" << response.value(i).as_string() << std::endl;
    }
    
    // 将回调函数包装成 std::function<void(etcd::Response)> 类型
    std::function<void(etcd::Response)> std_callback = [](etcd::Response resp) {
        callback(resp); // 调用原始的回调函数
    };

    // 监听指定键值对信息
    etcd::Watcher watcher(client, "/server", std_callback, true);
    watcher.Wait();


    return 0;
}