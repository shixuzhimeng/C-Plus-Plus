#include <iostream>
#include <string>
#include <unordered_map>
#include <coroutine>
#include <chrono>
#include <thread>
#include <exception>
#include <type_traits>

// ================= 0. 兼容性辅助结构体 =================
struct SuspendAlways {
    bool await_ready() const noexcept { return false; }
    void await_suspend(std::coroutine_handle<>) const noexcept {}
    void await_resume() const noexcept {}
};

// ================= 1. 协程任务封装 (AsyncTask) =================

// 前向声明
template<typename T>
struct AsyncTask;

// void 特化声明
template<>
struct AsyncTask<void>;

<<<<<<< Updated upstream
// 通用模板：只处理非 void 类型，仅保留 return_value
=======
//通用模板：只处理非 void 类型，仅保留 return_value
>>>>>>> Stashed changes
template<typename T>
struct AsyncTask {
    struct promise_type {
        T value;
        std::exception_ptr exception;

        AsyncTask get_return_object() {
            return AsyncTask{std::coroutine_handle<promise_type>::from_promise(*this)};
        }
        SuspendAlways initial_suspend() { return {}; }
        SuspendAlways final_suspend() noexcept { return {}; }
        void unhandled_exception() { exception = std::current_exception(); }
        
        // 仅保留 return_value
        void return_value(T val) { 
            value = std::move(val); 
        }
    };

    std::coroutine_handle<promise_type> handle;
    
    ~AsyncTask() { if (handle) handle.destroy(); }
    AsyncTask(const AsyncTask&) = delete;
    AsyncTask& operator=(const AsyncTask&) = delete;
    AsyncTask(AsyncTask&& other) noexcept : handle(other.handle) { other.handle = nullptr; }

    T get() {
        if (!handle) throw std::runtime_error("AsyncTask handle is null");
        if (handle.promise().exception) std::rethrow_exception(handle.promise().exception);
        return handle.promise().value;
    }
    
    auto operator co_await() {
        struct Awaiter {
            std::coroutine_handle<promise_type> h;
            bool await_ready() { return !h || h.done(); } 
            void await_suspend(std::coroutine_handle<> awaiting_coroutine) {
                if (!h) return;
                std::jthread([h = h]() {
                    std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
                    h.resume(); 
                });
            }
            T await_resume() { 
                if (!h) return T{};
                if (h.promise().exception) std::rethrow_exception(h.promise().exception);
                return h.promise().value; 
            }
        };
        return Awaiter{handle};
    }
};

<<<<<<< Updated upstream
// void 特化实现：仅保留 return_void
=======
//void 特化实现：仅保留 return_void
>>>>>>> Stashed changes
template<>
struct AsyncTask<void> {
    struct promise_type {
        std::exception_ptr exception;
        AsyncTask<void> get_return_object() {
            return AsyncTask<void>(); 
        }
        SuspendAlways initial_suspend() { return {}; }
        SuspendAlways final_suspend() noexcept { return {}; }
        void unhandled_exception() { exception = std::current_exception(); }
        
        // 仅保留 return_void
        void return_void() {}
    };

    std::coroutine_handle<promise_type> handle;
    
    AsyncTask() = default; 
    ~AsyncTask() { if (handle) handle.destroy(); }
    AsyncTask(const AsyncTask&) = delete;
    AsyncTask& operator=(const AsyncTask&) = delete;
    AsyncTask(AsyncTask&& other) noexcept : handle(other.handle) { other.handle = nullptr; }
    
    void get() {
        if (!handle) return;
        if (handle.promise().exception) std::rethrow_exception(handle.promise().exception);
    }

    auto operator co_await() {
        struct Awaiter {
            std::coroutine_handle<promise_type> h;
            bool await_ready() { return !h || h.done(); } 
            void await_suspend(std::coroutine_handle<> awaiting_coroutine) {
                if (!h) return;
                std::jthread([h = h]() {
                    std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
                    h.resume(); 
                });
            }
            void await_resume() { 
                if (h && h.promise().exception) std::rethrow_exception(h.promise().exception);
            }
        };
        return Awaiter{handle};
    }
};

// ================= 2. 聊天室业务逻辑与服务器 =================

struct NetworkPacket {
    std::string type;
    std::string username;
    std::string password;
    std::string token;
    std::string message;
    bool success = false;
};

AsyncTask<NetworkPacket> mock_network_io(const NetworkPacket& request) {
    std::cout << "[网络层] 发送请求: " << request.type << " (用户: " << request.username << ")" << std::endl;
    co_await SuspendAlways{}; 

    NetworkPacket response;
    response.type = request.type;
    response.username = request.username;
    response.success = true; 
    response.message = "Mock Success";
    
    co_return response;
}

class ChatServer {
public:
    struct Session {
        std::string token;
        bool is_logged_in = false;
    };

    AsyncTask<NetworkPacket> handleRegister(const std::string& username, const std::string& password) {
        NetworkPacket req{"REGISTER", username, password};
        NetworkPacket res = co_await mock_network_io(req);
        
        if (username.empty() || password.empty()) {
            res.success = false; res.message = "用户名或密码不能为空";
        } else if (users_.find(username) != users_.end()) {
            res.success = false; res.message = "用户已存在";
        } else {
            users_[username] = Session{};
            res.success = true; res.message = "注册成功，请登录";
        }
        co_return res;
    }

    AsyncTask<NetworkPacket> handleLogin(const std::string& username, const std::string& password) {
        NetworkPacket req{"LOGIN", username, password};
        NetworkPacket res = co_await mock_network_io(req);

        auto it = users_.find(username);
        if (it == users_.end()) {
            res.success = false; res.message = "用户不存在，请先注册";
        } else if (password != "123456") {
            res.success = false; res.message = "密码错误";
        } else {
            it->second.token = "TOKEN_" + username + "_" + std::to_string(rand());
            it->second.is_logged_in = true;
            res.success = true; 
            res.token = it->second.token;
            res.message = "登录成功";
            std::cout << "[服务器] 用户 " << username << " 已加入聊天室" << std::endl;
        }
        co_return res;
    }

    AsyncTask<NetworkPacket> handleLogout(const std::string& username, const std::string& token) {
        NetworkPacket req{"LOGOUT", username};
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

// ================= 3. 客户端协程业务流 =================

AsyncTask<void> clientWorkflow(ChatServer& server, const std::string& username, const std::string& password) {
    std::cout << "====== 客户端 (" << username << ") 开始操作 ======" << std::endl;

    auto regRes = co_await server.handleRegister(username, password);
    std::cout << "[客户端] 注册结果: " << regRes.message << std::endl;

    auto loginRes = co_await server.handleLogin(username, password);
    if (!loginRes.success) {
        std::cout << "[客户端] 登录失败，终止流程: " << loginRes.message << std::endl;
        co_return;
    }
    std::cout << "[客户端] 登录成功，获取 Token: " << loginRes.token << std::endl;

    std::cout << "[客户端] 正在聊天室中潜水..." << std::endl;
    co_await SuspendAlways{}; 

    auto logoutRes = co_await server.handleLogout(username, loginRes.token);
    std::cout << "[客户端] 注销结果: " << logoutRes.message << std::endl;
    
    std::cout << "====== 客户端 (" << username << ") 流程结束 ======\n" << std::endl;
}

// ================= 4. 主函数驱动 =================
int main() {
    try {
        ChatServer server;

        auto task1 = clientWorkflow(server, "Alice", "123456");
        auto task2 = clientWorkflow(server, "Bob", "123456");
        auto task3 = clientWorkflow(server, "Alice", "654321"); 

        task1.handle.resume();
        task2.handle.resume();
        task3.handle.resume();
        
        std::this_thread::sleep_for(std::chrono::seconds(2));
        
    } catch (const std::exception& e) {
        std::cerr << "程序发生异常: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
