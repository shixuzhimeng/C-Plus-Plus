#include <iostream>
#include <coroutine>

class Generation{
public:
    struct promise_type {
        int value{0};
        Generation get_return_object() {
            return Generation{std::coroutine_handle<promise_type>::from_promise(*this)};
        }
        std::suspend_always initial_suspend() {
            return {};
        }
        std::suspend_always final_suspend() noexcept{
            return {};
        }
        std::suspend_always yield_value(int value) {
            this->value = value;
            return {};
        }
        void return_void() {
            std::cout << "协程结束" << std::endl;
        }
        void unhandled_exception() {
            std::terminate();
        }
    };

    void next () {
        handle.resume();
    }

    int value() {
        return handle.promise().value;
    }

    std::coroutine_handle<promise_type> handle;
    Generation(std::coroutine_handle<promise_type> h) : handle(h) {}
    ~Generation() {
        if(handle) {
            handle.destroy();
        }
    }
};

Generation fib() {
    static int prev1 = 0;
    static int prev2 = 1;

    while(true) {
        int cur = prev1;
        int next = prev1 + prev2;

        prev1 = prev2;
        prev2 = next;

        co_yield cur;
    }
}

void demo () {
    auto gen = fib();
    for(int i = 0; i < 5; i++) {
        // 协程恢复执行
        gen.next();
        // 打印下一个数字
        std::cout << gen.value() << std::endl;
    
    }
}

int main () {
    demo();
    return 0;
}