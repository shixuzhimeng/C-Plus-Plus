#define ASIO_ENABLE_CONCEPTS
#define ASIO_HAS_CO_AWAIT

// 包含一个启动协程的函数
#include <boost/asio/co_spawn.hpp>

// 分离协程
#include <boost/asio/detached.hpp>

// 协程调度的执行器
#include <boost/asio/io_context.hpp>

// 网络编程IP/TCP的头文件
#include <boost/asio/ip/tcp.hpp>

// 信号的处理
#include <boost/asio/signal_set.hpp>

// 发送/写的头文件
#include <boost/asio/write.hpp>

// 协程等待
#include <boost/asio/awaitable.hpp>

#include <iostream>

// 指定展开一些命名空间,方便后续的操作
using boost::asio::ip::tcp;
using boost::asio::awaitable;
using boost::asio::co_spawn;
using boost::asio::detached;
using boost::asio::use_awaitable;

using std::cout;
using std::endl;

namespace this_coro = boost::asio::this_coro;

awaitable <void> echo(tcp::socket socket) {
    try {
        char data[1024];
        for(;;) {
            // 异步接受获取数据的字节数
            std::size_t n = co_await socket.async_read_some(boost::asio::buffer(data), use_awaitable);
            // 发送数据
            co_await async_write(socket, boost::asio::buffer(data, n), use_awaitable);
        }
    }
    catch(std::exception& e) {
        cout << "Echo exception is " << e.what() << endl;
    }
}

awaitable <void> listener() {
    // 这里我们调用co_await异步地去找调度器
    auto executor = co_await this_coro::executor;
    // 我们找到了调度器之后，我们就需要接受端口了
    tcp::acceptor acceptor(executor, {tcp::v4(), 6666});
    for(;;) {
        tcp::socket socket = co_await acceptor.async_accept(use_awaitable);
        co_spawn(executor, echo(std::move(socket)), detached);
    }
}


int main() {
    try {
        boost::asio::io_context io_context(1);
        boost::asio::signal_set signals(io_context, SIGINT, SIGTERM);
        signals.async_wait([&](auto, auto) {
            io_context.stop();
        });
        // 创建协程
        co_spawn(io_context, listener(), detached);
        io_context.run();

    }
    catch (std::exception& e){
        cout << "Exception is " << e.what() << endl;
    }

    return 0;
}