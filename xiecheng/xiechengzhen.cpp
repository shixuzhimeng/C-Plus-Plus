#include <iostream>
#include <coroutine>

struct CoroManager {
    struct promise_type {
        static void* operator new(size_t size) {
            void *ptr = ::operator new(size);
            std::cout << "分配协程帧内存" << ptr << " " << size << std::endl;
            return ptr;
        }
        static void operator delete(void* ptr) {
            std::cout << "释放协程" << ptr << std::endl;
            ::operator delete(ptr);
        }
        CoroManager get_return_object() {
            return CoroManager(std::coroutine_handle<promise_type>::from_promise(*this));
        }
        std::suspend_always initial_suspend() {
            return {};
        }
        void return_void() {
            std::cout << "协程结束" << std::endl;
        }
        std::suspend_always final_suspend() noexcept{
            return {};
        }
        void unhandled_exception() {}
    };
    std::coroutine_handle<promise_type> handle;
    CoroManager (std::coroutine_handle<promise_type> handle) : handle(handle) {}
    void resume() {
        handle.resume();
    }
    ~CoroManager() {
        handle.destroy();
    }
};

CoroManager my_function() {
    std::cout << "协程开始" << std::endl;
    co_return;
}

int main() {
    CoroManager coro = my_function();
    coro.resume();
    return 0;
}