// 二次封装：封装etcd-client-api，实现两种类型的客户端
// 1. 服务注册客户端：向服务器新增服务信息数据，并进行保活
// 2. 服务发现客户端：从服务器查找服务信息数据，并进行改变事件监控
// 封装的时候，我们尽量减少模块之间的耦合度，本质上etcd是一个键值存储系统，并不是专门用于作为注册中心进行服务注册和发现的。

// 封装思想：
// 1. 封装服务注册客户端类
// 提供一个接口：向服务器新增数据并进行保活
// 参数：注册中心地址（etcd服务器地址），新增的服务信息（服务名-主机地址键值对）
// 2. 封装服务发现客户端类
// 提供两个设置回调函数的接口：服务上线事件接口（数据新增），服务下线事件接口（数据删除）
// 提供一个设置根目录的接口：用于获取指定目录下的数据以及监控目录下数据的改变

#pragma once
#include <etcd/Client.hpp>
#include <etcd/KeepAlive.hpp>
#include <etcd/Response.hpp>
#include <etcd/Watcher.hpp>
#include <etcd/Value.hpp>
#include <functional>
#include "logger.hpp"

namespace bite_im
{
    // 服务注册客户端类
    class Registry
    {
    public:
        using ptr = std::shared_ptr<Registry>;
        Registry(const std::string &host) : _client(std::make_shared<etcd::Client>(host)),
                                            _keep_alive(_client->leasekeepalive(3).get()),
                                            _lease_id(_keep_alive->Lease()) {}
        ~Registry() { _keep_alive->Cancel(); }
        bool registry(const std::string &key, const std::string &val)
        {
            auto resp = _client->put(key, val, _lease_id).get();
            if (resp.is_ok() == false)
            {
                LOG_ERROR("注册数据失败：{}", resp.error_message());
                return false;
            }
            return true;
        }

    private:
        std::shared_ptr<etcd::Client> _client;
        std::shared_ptr<etcd::KeepAlive> _keep_alive;
        uint64_t _lease_id;
    };

    // 服务发现客户端类
    class Discovery
    {
    public:
        using ptr = std::shared_ptr<Discovery>;
        using NotifyCallback = std::function<void(std::string, std::string)>;
        Discovery(const std::string &host,
                  const std::string &basedir,
                  const NotifyCallback &put_cb,
                  const NotifyCallback &del_cb) : _client(std::make_shared<etcd::Client>(host)),
                                                  _put_cb(put_cb), _del_cb(del_cb)
        {
            // 先进行服务发现,先获取到当前已有的数据
            auto resp = _client->ls(basedir).get();
            if (resp.is_ok() == false)
            {
                LOG_ERROR("获取服务信息数据失败：{}", resp.error_message());
            }
            int sz = resp.keys().size();
            for (int i = 0; i < sz; ++i)
            {
                if (_put_cb)
                    _put_cb(resp.key(i), resp.value(i).as_string());
            }
            // 然后进行事件监控，监控数据发生的改变并调用回调进行处理
            _watcher = std::make_shared<etcd::Watcher>(*_client.get(), basedir,
                                                       std::bind(&Discovery::callback, this, std::placeholders::_1), true);
        }
        ~Discovery()
        {
            _watcher->Cancel();
        }

    private:
        void callback(const etcd::Response &resp)
        {
            if (resp.is_ok() == false)
            {
                LOG_ERROR("收到一个错误的事件通知: {}", resp.error_message());
                return;
            }
            for (auto const &ev : resp.events())
            {
                if (ev.event_type() == etcd::Event::EventType::PUT)
                {
                    if (_put_cb)
                        _put_cb(ev.kv().key(), ev.kv().as_string());
                    LOG_DEBUG("新增服务：{}-{}", ev.kv().key(), ev.kv().as_string());
                }
                else if (ev.event_type() == etcd::Event::EventType::DELETE_)
                {
                    if (_del_cb)
                        _del_cb(ev.prev_kv().key(), ev.prev_kv().as_string());
                    LOG_DEBUG("下线服务：{}-{}", ev.prev_kv().key(), ev.prev_kv().as_string());
                }
            }
        }

    private:
        NotifyCallback _put_cb;
        NotifyCallback _del_cb;
        std::shared_ptr<etcd::Client> _client;
        std::shared_ptr<etcd::Watcher> _watcher;
    };
}