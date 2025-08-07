#include <etcd/Client.hpp>
#include <etcd/Response.hpp>
#include <etcd/KeepAlive.hpp>
#include <thread>

int main()
{
    std::string registry_host = "http://127.0.0.1:2379";
    // 为了防止多主机注册相同服务时，信息覆盖，
    // 因此每个主机在服务名后加入自己的实例名称，相当于各有各的服务-主机键值对
    std::string service_key = "/service/user/instance";
    std::string service_host = "112.23.23.120:9090";
    etcd::Client etcd(registry_host);

    // 对客户端创建一个指定时长的租约，若租约到期则创建的键值将被撤销
    // 对客户端创建一个指定时长的租约，若租约到期则创建的键值将被撤销
    // 通过租约进行保活探测，若服务提供端掉线，则租约到期后 etcd 会给服务发现者发送服务下线通知
    etcd::Response resp = etcd.leasegrant(3).get(); // 设置一个 3s 的租约
    // auto lease_id = resp.value().lease(); // 获取租约 ID
    // 租约保活的同时，创建一个保活的 3s 租约保活对象--也就是一旦断开连接，3s 后租约失效
    std::shared_ptr<etcd::KeepAlive> keepalive = etcd.leasekeepalive(3).get();
    auto lease_id = keepalive->Lease();
    auto resp_task = etcd.put(service_key, service_host, lease_id); // 注册服务
    // 修改变量名，避免冲突
    auto put_resp = resp_task.get();
    if (!put_resp.is_ok())
    {
        std::cout << put_resp.error_message() << std::endl;
        return -1;
    }
    std::cout << "添加数据成功！" << std::endl;
    getchar(); // 回车后撤销租约
    // 租约的撤销
    etcd.leaserevoke(lease_id);

    return 0;
}