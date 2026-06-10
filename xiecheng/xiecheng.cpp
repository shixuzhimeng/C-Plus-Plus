#include <iostream>
#include <coroutine>
#include <exception>

class CoroRALL {
public:
    class promise_type {
        public:
        int _my_value;
        // 创建协程操作管理对象
        CoroRALL get_return_object() {
            //std::cout << "get_return_object" << std::endl;
            return CoroRALL(std::coroutine_handle<promise_type>::from_promise(*this));
        }

        // 决定协程创建之后是否马上执行
        // std::suspend_never:不挂起
        // std::suspned_always:挂起
        std::suspend_always initial_suspend() {
            //std::cout << "initial_suspend" << std::endl;
            return {};
        }

        // return 和 value不能同时使用
        // void return_void() {
        //     std::cout << "协程函数逻辑结束" << std::endl;
        // }
        //
        // void return_value(int value) {
        //     _my_value = value;
        // }

        std::suspend_always yield_value(int value) {
            this->_my_value = value;
            return {};
        }

        // 协程执行完之后，是否马上就销毁
        // std::suspend_always：挂起，不立即销毁，等待外部destroy释放资源
        // std::suspend_never：不挂起，立即销毁
        std::suspend_always final_suspend() noexcept{
            //std::cout << "final_suspend" << std::endl;
            return {};
        }

        

        // 协程中有未处理的异常时如何处理
        void unhandled_exception() {
            std::cout << "未处理的异常" << std::endl;
            std::terminate();
        }
    };

    // 如果模板为空，表示handle只能控制协程的创建，销毁，恢复。
    // 如果传入参数，那么就可以获取value的值了
    std::coroutine_handle<promise_type> handle;
    
    CoroRALL(std::coroutine_handle<promise_type> handle) {
        //std::cout << "函数构造" << std::endl;
        this->handle = handle;
    }

    void resume() {
        if(!handle.done()) {
            handle.resume();
        }
    }

    int value() {
        return handle.promise()._my_value;
    }

    ~CoroRALL() {
        if(handle) {
            handle.destroy();
        }
    }
};

// 暂停：保存函数的状态（局部变量，参数信息，暂停的位置）
// 恢复：恢复函数的状态
CoroRALL my_coroutine() {
    co_yield 10;
    co_yield 20;
    co_yield 30;
    // std::cout << "协程执行" << std::endl;
    // throw std::runtime_error("");
    // std::cout << "协程执行" << std::endl;
    // //co_return;
    // co_return 100;
    // std::cout << "协程执行" << std::endl;

}


int main() {
    // 普通函数：一旦调用马上执行
    // 协程函数：一旦调用返回协程管理对象
    //std::coroutine_handle<> coro = my_coroutine();
    CoroRALL coro = my_coroutine();
    //coro.resume();

    //std::cout << coro.handle.promise()._my_value << std::endl;
    //std::cout << coro.value() << std::endl;

    // 协程管理的对象需要手动释放（创建协程的时候，编译器会在堆上给函数状态分配内存）
    //coro.destroy();
    
    coro.handle.resume();
    std::cout << "第一次的返回值" << coro.handle.promise()._my_value << std::endl;
    
    coro.handle.resume();
    std::cout << "第二次的返回值" << coro.handle.promise()._my_value << std::endl;
    
    coro.handle.resume();
    std::cout << "第三次的返回值" << coro.handle.promise()._my_value << std::endl;
    
    return 0;
}