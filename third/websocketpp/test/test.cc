#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

#include <iostream>
#include <functional>

typedef websocketpp::server<websocketpp::config::asio> server;

void on_message(server *s, websocketpp::connection_hdl hdl, server::message_ptr msg)
{
    std::cout << "on_message called with hdl: "
              << hdl.lock().get()
              << " and message: " << msg->get_payload()
              << std::endl;

    auto connection = s->get_con_from_hdl(hdl);
    connection->send(msg->get_payload() + "echo", websocketpp::frame::opcode::value::text);

    // s->send(hdl, msg->get_payload(), msg->get_opcode());
}

int main()
{
    server ws_server;

    // 初始化日志输出
    // ws_server.set_access_channels(websocketpp::log::alevel::all);
    // ws_server.clear_access_channels(websocketpp::log::alevel::frame_payload);
    ws_server.clear_access_channels(websocketpp::log::alevel::none);

    ws_server.init_asio();
    // 注册消息处理函数
    ws_server.set_open_handler([](websocketpp::connection_hdl hdl)
                               { std::cout << "on_open called with hdl: " << std::endl; });
    ws_server.set_close_handler([](websocketpp::connection_hdl hdl)
                                { std::cout << "on_close called with hdl: " << std::endl; });
    ws_server.set_message_handler(bind(on_message, &ws_server, std::placeholders::_1, std::placeholders::_2));

    ws_server.listen(9002);

    ws_server.start_accept();

    ws_server.run();

    return 0;
}
