#include <iostream>
using namespace std;

// //初始化列表
// class Date {
// public:
//     Date(int year, int month, int day)
//         :_year(_year)
//         ,_month(_month)
//         ,_day(_day)
//     {}
// private:
//     int _year;
//     int _month;
//     int _day;
// };

// //构造函数体赋值
// class Date {
// public:
//     Date(int year, int month, int day) {
//         _year = year;
//         _month = month;
//         _day = day;
//     }

// private:
//     int _year;
//     int _month;
//     int _day;
// };

// class A {
// public:
//     A(int a)
//     :_a(a)
//     {
//         cout << _a << endl;
//     }
// private:
//     int _a;
// };
// class B {
// public:
//     B(int a, int ref)
//     :_ref(ref)
//     ,_n(1)
//     ,_x(2)
//     ,_aobj(a)
//     {}
// private:
//     A _aobj;
//     int& _ref;    //引用
//     const int _n; //const成员

//     int _x = 1;   //这里的1是缺省值，缺省值是给初始化列表的
// };

// class A {
// public:
//     //没有this指针，指定类域和访问限定符就可以访问
//     static int GetACount() {

//     }
// private:
//     //成员变量  --  属于每一个类对象，储存对象里面
//     int _a1 = 1;
//     int _a2 = 2;
//     //静态成员变量  --  属于类，属于类的每个对象共享，存储在静态区
//     //不可以给缺省值
//     static int _count;
// };

// //全局变量的劣势：任何地方可以随意改变
// //全局位置，类外面定义
// int A::_count = 1;
// class B;
// class A {
// public:
//     class B;
// private:
//     class B {
//         public:
//         private:
//     };
// };


int main () {
    int *a = new int;
    //动态申请10个int类型的空间
    int *b = new int[10];
    //初始化为3
    int *c = new int(3);
    
    delete a;
    delete[] b;
    delete c;

    
    return 0;
}