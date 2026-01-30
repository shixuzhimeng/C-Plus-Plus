#include <iostream>
using namespace std;

// class test {
  
//     int _a;
// };

// class test2 {};

// int main() {
//     test t1;
//     test2 t2;

//     cout << sizeof(t1) << endl;
//     cout << sizeof(t2) << endl;
    
//     return 0;

// }

// class test {
// public:
//     void Init(int year, int day, int month) {
//         int _year;
//         int _day;
//         int _month;
//     }

//     void print() {
//         cout << _year << _day << _month << endl;
//     }

//     void print(Data* const this) {
//         cout << this->_year << this->_day << this->_month << endl;
//     }

//     int _year;
//     int _day;
//     int _month;
// };

// class A {
// public:
//     void Print() {
//         cout << "Print" << endl;
//     }
// private:
//     int _a;
// };

// int main() {
//     A* p = nullptr;
//     p->Print();
//     return 0;
// }

// class A {
// public:
//     void PrintA() {
//         cout << _a << endl;
//     }
// private:
//     int _a;
// };

// int main() {
//     A* p = nullptr;
//     p->PrintA();
//     return 0;
// }

//构造函数
//函数名和类名相同
// typedef int DataType;
// class test {
// public:
//     test(int capacity = 4) {
//         cout << "Init" << endl;
//         _array = (DataType*)malloc(sizeof(DataType) * capacity);
//         if(NULL == _array) {
//             perror("falied");
//             return ;
//         }
//         _capacity = capacity;
//         _size = 0;
//     }


// private:
//     DataType* _array;
//     int _size;
//     int _capacity;
// };

// class test {
// public:
//     void print() {
//         cout << _year << " " << _month << " " << _day << endl;
//     }
// private:
//     //内置类型
//     //C++11支持，这里不是初始化，因为这里就是声明
//     //这里给的值是默认的缺省值，给默认构造函数使用
//     int _year = 1;
//     int _month = 1;
//     int _day = 1;
// };

// typedef int DataType;
// class test {
// public:
//     test(int capacity = 4) {
//         cout << "Init" << endl;
//         _array = (DataType*)malloc(sizeof(DataType) * capacity);
//         if(NULL == _array) {
//             perror("falied");
//             return ;
//         }
//         _capacity = capacity;
//         _size = 0;
//     }
//     void Init(DataType x) {
//         _capacity = x;
//         _size = x;
//     }


// private:
//     DataType* _array;
//     int _size;
//     int _capacity;
// };

// int main() {
//     //构造函数
//     test t1(1);
//     //一般函数
//     test t2;
//     t2.Init(4);
    
//     return 0;
// }

class test {
public:
    //构成函数重载
    //但是在无参调用时存在歧义
    // test() {
    //     _year = 1;
    //     _month = 1;
    //     _day = 1;
    // }
    //这样最好
    test(int year = 1, int month = 1, int day = 1) {
        _year = year;
        _month = month;
        _day = day;
    }

private:
    int _year = 1;
    int _month = 1;
    int _day = 1;
};