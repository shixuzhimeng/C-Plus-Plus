#include <iostream>
#include <coroutine>
#include <thread>
#include <chrono>
#include <memory>

// 1. 核心：Task 协程包装器
template<typename T>
struct Task {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    struct promise_type {
        T result; // 存储返回值
        std::exception_ptr except;
        
        Task get_return_object() { 
            return Task{handle_type::from_promise(*this)}; 
        }
        std::suspend_always initial_suspend() noexcept { return {}; } 
        std::suspend_always final_suspend() noexcept { return {}; }  
        
        void return_value(T value) noexcept { result = value; } // 处理 co_return T
        
        void unhandled_exception() noexcept { except = std::current_exception(); }
    };

    handle_type handle;
    explicit Task(handle_type h) : handle(h) {}
    ~Task() { if (handle) handle.destroy(); }

    bool await_ready() const noexcept { return handle.done(); }
    void await_suspend(std::coroutine_handle<> h) noexcept { handle.resume(); }
    T await_resume() {
        if (handle.promise().except) std::rethrow_exception(handle.promise().except);
        return handle.promise().result;
    }
};

// 2. void 类型不能声明变量
template<>
struct Task<void> {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    struct promise_type {
        std::exception_ptr except;
        
        Task get_return_object() { 
            return Task{handle_type::from_promise(*this)}; 
        }
        std::suspend_always initial_suspend() noexcept { return {}; } 
        std::suspend_always final_suspend() noexcept { return {}; }  
        
        void return_void() noexcept {} // void 协程使用 return_void
        
        void unhandled_exception() noexcept { except = std::current_exception(); }
    };

    handle_type handle;
    explicit Task(handle_type h) : handle(h) {}
    ~Task() { if (handle) handle.destroy(); }

    bool await_ready() const noexcept { return handle.done(); }
    void await_suspend(std::coroutine_handle<> h) noexcept { handle.resume(); }
    void await_resume() { // await_resume 返回 void
        if (handle.promise().except) std::rethrow_exception(handle.promise().except);
    }
};

// 3. 异步延时 Awaiter（安全版）
struct AsyncSleepAwaiter {
    std::chrono::milliseconds delay;
    bool await_ready() const noexcept { return false; }
    void await_suspend(std::coroutine_handle<> h) const {
        auto safe_handle = std::shared_ptr<void>(nullptr, [h](void*) { 
            if (!h.done()) h.destroy(); 
        });
        
        std::thread([h, d = delay, safe_handle]() mutable {
            std::this_thread::sleep_for(d);
            if (!h.done()) h.resume();
        }).detach();
    }
    void await_resume() const noexcept {}
};

// 4. 业务协程函数
Task<int> download_data(int id, int ms) {
    std::cout << "[Task " << id << "] 开始下载...\n";
    co_await AsyncSleepAwaiter{std::chrono::milliseconds(ms)}; 
    std::cout << "[Task " << id << "] 下载完成!\n";
    co_return id * 100; 
}

Task<void> process_pipeline() {
    std::cout << "=== 流水线并发开始 ===\n";
    
    auto task1 = download_data(1, 800);
    auto task2 = download_data(2, 500);
    
    task1.handle.resume(); 
    task2.handle.resume(); 
    
    int size1 = co_await task1; 
    int size2 = co_await task2; 
    
    std::cout << "总数据量: " << size1 + size2 << "\n";
}

int main() {
    std::cout << "主线程启动调度器...\n";
    auto task = process_pipeline();
    task.handle.resume(); 
    
    std::this_thread::sleep_for(std::chrono::seconds(2)); 
    
    std::cout << "主线程退出。\n";
    return 0;
}