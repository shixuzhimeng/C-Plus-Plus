#include <iostream>
using namespace std;

// struct test {
//     //成员函数
//     void Init(int defaultCapacity = 4) {
//         int* a = (int*)malloc(sizeof(int)*capacity);
//         if(nullptr == a)
//         {
//             perror("malloc failed");
//             return ;
//         }
//     }
//     //成员变量
//     int* a;
//     int size;
//     int capacity;
// };

// int main() {
//     test s;
//     s.size = 4;
//     s.Init(10);
//     return 0;
// }

// class test {
// public:
//     inline void Init(int defaultCapacity = 4) {
//         a = (int*)malloc(sizeof(int)*capacity);
//         if(nullptr == a)
//         {
//             perror("malloc failed");
//             return ;
//         }
//     }
//     void Destory() {
//         free(a);
//         a = nullptr;
//         size = capacity = 0;
//     }
//     int* a;
//     int size;
//     int capacity;
// };

// int main() {
//     test s;
//     s.Init(10);
//     return 0;
// }

class test {
public:
    void Init(int year) {
        _year = year;
    }

    int _year;
    int _month;
    int _day;
};

int main() {
    test t1;
    t1._year = 10;
    //但是不能直接存
    //t2.day = 1;

    cout << sizeof(t1) << endl;
}