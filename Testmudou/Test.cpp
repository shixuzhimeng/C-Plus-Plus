#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <iostream>
#include <functional>

using namespace muduo;
using namespace muduo::net;
using namespace std::placeholders;

class EchoServer {
public:
    // 1. 构造函数：初始化TcpServer，并注册回调函数
    EchoServer(EventLoop* loop, const InetAddress& listenAddr, const string& nameArg)
        : server_(loop, listenAddr, nameArg), loop_(loop) {
        // 注册“新连接建立/断开”的回调
        server_.setConnectionCallback(std::bind(&EchoServer::onConnection, this, _1));
        // 注册“收到消息”的回调，这是处理业务逻辑的地方
        server_.setMessageCallback(std::bind(&EchoServer::onMessage, this, _1, _2, _3));
        // 2. 设置线程数（1个I/O线程，3个工作线程）
        server_.setThreadNum(4);
    }

    void start() {
        server_.start(); // 启动服务器监听
    }

private:
    // 处理连接事件的回调函数
    void onConnection(const TcpConnectionPtr& conn) {
        if (conn->connected()) {
            std::cout << "新客户端上线: " << conn->peerAddress().toIpPort() << std::endl;
        } else {
            std::cout << "客户端断开: " << conn->peerAddress().toIpPort() << std::endl;
            conn->shutdown(); // 关闭连接
        }
    }

    // 处理消息事件的回调函数（业务逻辑）
    void onMessage(const TcpConnectionPtr& conn, Buffer* buffer, Timestamp time) {
        // 从缓冲区取出所有数据
        std::string msg = buffer->retrieveAllAsString();
        std::cout << "收到数据: " << msg << " 时间: " << time.toString() << std::endl;
        // 将数据原样发回给客户端
        conn->send(msg);
    }

    TcpServer server_;
    EventLoop* loop_;
};

int main() {
    // 3. 创建事件循环对象（epoll的核心）
    EventLoop loop;
    // 4. 指定服务器监听的IP和端口
    InetAddress listenAddr("127.0.0.1", 6000);
    // 5. 创建服务器实例
    EchoServer server(&loop, listenAddr, "EchoServer");
    // 6. 启动服务器
    server.start();
    // 7. 开启事件循环，程序会在这里一直运行，等待事件发生
    loop.loop();
    return 0;
}