#include <iostream>
#include <coroutine>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <chrono>

// 全局事件循环调度器
class Event {
public:
    void add_task(std::coroutine_handle<> handle) {
        {
            std::lock_guard<std::mutex> lock(my_mutex);
            my_queue.push(handle);            
        }
        ++number;
    }

    void post(std::coroutine_handle<> handle) {
        {
            std::lock_guard<std::mutex> lock(my_mutex);
            my_queue.push(handle);
        }
        my_cv.notify_one();
    }

    void run() {
        while (true) {
            std::coroutine_handle<> my_handle;
            {
                std::unique_lock<std::mutex> lock(my_mutex);
                my_cv.wait(lock, [&] {
                    return !my_queue.empty() || number == 0; 
                });

                if (my_queue.empty() && number == 0) {
                    std::cout << "任务执行完毕" << std::endl;
                    break;
                }

                my_handle = my_queue.front();
                my_queue.pop();
            }

            if (!my_handle) {
                continue;
            }

            my_handle.resume();

            if (my_handle.done()) {
                --number;
                my_handle.destroy();
            }
        }
    }

private:
    std::queue<std::coroutine_handle<>> my_queue;
    std::mutex my_mutex;
    std::condition_variable my_cv;
    size_t number{0};
};

Event eloop;

// 协程任务包装类
class task {
public:
    struct promise_type {
        task get_return_object() {
            return task{std::coroutine_handle<promise_type>::from_promise(*this)};
        }

        std::suspend_always initial_suspend() {
            return {};
        }

        std::suspend_always final_suspend() noexcept {
            return {};
        }

        void return_void() {}

        void unhandled_exception() {
            std::terminate();
        }
    };

    std::coroutine_handle<promise_type> handle;

    task(std::coroutine_handle<promise_type> h) : handle(h) {}

    // 允许隐式转换为底层句柄
    operator std::coroutine_handle<>() {
        return handle;
    }

    void release() {
        handle = nullptr;
    }

    ~task() {
        if (handle) {
            handle.destroy();
        }
    }
};

// 异步延时等待器
struct Awaiter {
    int time{0};

    bool await_ready() {
        return false;
    }

    void await_suspend(std::coroutine_handle<> handle) {
        std::thread([handle, duration = time] {
            std::this_thread::sleep_for(std::chrono::seconds(duration));
            eloop.post(handle);
        }).detach();
    }

    void await_resume() {}
};

// 测试协程任务
task task1() {
    std::cout << "task 1 开始" << std::endl;
    co_await Awaiter{5};
    std::cout << "task 1 结束" << std::endl;
}

task task2() {
    std::cout << "task 2 开始" << std::endl;
    co_await Awaiter{3};
    std::cout << "task 2 结束" << std::endl;
}

int main() {
    auto start = std::chrono::steady_clock::now();

    auto t1 = task1();
    auto t2 = task2();

    // 将任务添加到调度器
    eloop.add_task(t1);
    eloop.add_task(t2);

    t1.release();
    t2.release();

    // 启动事件循环
    eloop.run();

    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "程序耗时: " << duration.count() << " 毫秒" << std::endl;

    return 0;
}