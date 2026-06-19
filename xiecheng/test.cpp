#include <iostream>
#include <coroutine>
#include <string>
template<typename T>
struct AsyncTask {
    struct promise_type {
        T value;
        std::exception_ptr exception;

        AsyncTask get_return_object() {
            return AsyncTask{std::coroutine_handle<promise_type>::from_promise(*this)};
        }
        std::suspend_always initial_suspend() { 
            return {}; 
        }
        std::suspend_always final_suspend() noexcept { 
            return {};
        }
        void unhandled_exception() {
            exception = std::current_exception();
        }
        
        template<typename U> void return_value(U&& val) {
            value = std::forward<U>(val);
        }
        void return_void() {}
    };

    std::coroutine_handle<promise_type> handle;
    
    // RAII 管理协程句柄，防止内存泄漏
    ~AsyncTask() {
        if (handle)
            handle.destroy();
    }
    // 禁止拷贝，允许移动
    AsyncTask(const AsyncTask&) = delete;
    AsyncTask& operator=(const AsyncTask&) = delete;
    AsyncTask(AsyncTask&& other) noexcept : handle(other.handle) { 
        other.handle = nullptr;
    }

    // 获取协程返回值
    T get() {
        if (handle.promise().exception) 
            std::rethrow_exception(handle.promise().exception);
        return handle.promise().value;
    }
    
    // 支持 co_await
    auto operator co_await() {
        struct Awaiter {
            std::coroutine_handle<promise_type> h;
            bool await_ready() { 
                return false;
            } // 总是挂起，交由外部调度器恢复
            void await_suspend(std::coroutine_handle<> awaiting_coroutine) {
                // 在实际网络框架中，这里会将 awaiting_coroutine 注册到 IO 完成端口
                // 当网络数据到达时，IO 线程会调用 h.resume()
                std::thread([h = h, awaiting_coroutine]() {
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                    h.resume(); 
                }).detach();
            }
            T await_resume() { return h.promise().value; }
        };
        return Awaiter{handle};
    }
};
// 模拟网络请求/响应的数据结构
struct NetworkPacket {
    std::string type; // "REGISTER", "LOGIN", "LOGOUT", "CHAT"
    std::string username;
    std::string password;
    std::string token;
    std::string message;
    bool success;
};

// 模拟底层异步网络 IO
AsyncTask<NetworkPacket> mock_network_io(const NetworkPacket& request) {
    std::cout << "[网络层] 发送请求: " << request.type << " (用户: " << request.username << ")" << std::endl;
    // co_await 会触发 AsyncTask::Awaiter::await_suspend，模拟异步挂起
    NetworkPacket response = co_await AsyncTask<NetworkPacket>{nullptr}; 
    // 在实际 asio 中，这里会是 co_await socket.async_read_some(...)
    // 这里的 response 将由外部模拟填充
    co_return response;
}

class ChatServer {
public:
    // 用户会话结构
    struct Session {
        std::string token;
        bool is_logged_in = false;
    };

    // 处理注册
    AsyncTask<NetworkPacket> handleRegister(const std::string& username, const std::string& password) {
        NetworkPacket req{"REGISTER", username, password};
        
        // 1. 协程挂起，等待网络返回注册结果
        NetworkPacket res = co_await mock_network_io(req);
        
        // 模拟服务器校验逻辑
        if (username.empty() || password.empty()) {
            res.success = false; res.message = "用户名或密码不能为空";
        } else if (users_.find(username) != users_.end()) {
            res.success = false; res.message = "用户已存在";
        } else {
            users_[username] = Session{}; // 预创建用户
            res.success = true; res.message = "注册成功，请登录";
        }
        co_return res;
    }

    // 处理登录
    AsyncTask<NetworkPacket> handleLogin(const std::string& username, const::string& password) {
        NetworkPacket req{"LOGIN", username, password};
        
        // 2. 协程挂起，等待网络返回登录结果
        NetworkPacket res = co_await mock_network_io(req);

        auto it = users_.find(username);
        if (it == users_.end()) {
            res.success = false; res.message = "用户不存在，请先注册";
        } else if (password != "123456") { // 模拟简单密码校验
            res.success = false; res.message = "密码错误";
        } else {
            // 生成 Token 并标记在线
            it->second.token = "TOKEN_" + username + "_" + std::to_string(rand());
            it->second.is_logged_in = true;
            res.success = true; 
            res.token = it->second.token;
            res.message = "登录成功";
            std::cout << "[服务器] 用户 " << username << " 已加入聊天室" << std::endl;
        }
        co_return res;
    }

    // 处理注销
    AsyncTask<NetworkPacket> handleLogout(const std::string& username, const std::string& token) {
        NetworkPacket req{"LOGOUT", username};
        
        // 3. 协程挂起，等待网络返回注销结果
        NetworkPacket res = co_await mock_network_io(req);

        auto it = users_.find(username);
        if (it != users_.end() && it->second.token == token) {
            it->second.is_logged_in = false;
            it->second.token.clear();
            res.success = true; res.message = "注销成功";
            std::cout << "[服务器] 用户 " << username << " 已离开聊天室" << std::endl;
        } else {
            res.success = false; res.message = "未登录或 Token 无效";
        }
        co_return res;
    }

private:
    std::unordered_map<std::string, Session> users_;
};
