#include <etcd/Client.hpp>
#include <etcd/Response.hpp>
#include <etcd/KeepAlive.hpp>
#include <thread>

int main(int argc, char *argv[])
{
    std::string etcd_host = "127.0.0.1:2379";
    // 实例化客户端对象
    etcd::Client client(etcd_host);
    // 获取租约包活对象
    auto keep_alive = client.leasekeepalive(10).get();
    // 租约 ID
    int64_t lease_id = keep_alive->Lease();
    // 新增数据
    auto response1 = client.put("/server/user", "127.0.0.1:8080", lease_id).get();
    if (!response1.is_ok())
    {
        std::cout << "put failed, error: " << response1.error_message() << std::endl;
        return -1;
    }

    auto response2 = client.put("/server/user", "127.0.0.1:8081", lease_id).get();
    if (!response2.is_ok())
    {
        std::cout << "put failed, error: " << response2.error_message() << std::endl;
        return -1;
    }

    auto response3 = client.put("/server/user", "127.0.0.1:8082", lease_id).get();
    if (!response3.is_ok())
    {
        std::cout << "put failed, error: " << response3.error_message() << std::endl;
        return -1;
    }
    
    std::this_thread::sleep_for(std::chrono::seconds(10));
    return 0;
}
