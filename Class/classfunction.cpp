#include <iostream>
using namespace std;

//初始化列表
class Date {
public:
    Date(int year, int month, int day)
        :_year(_year)
        ,_month(_month)
        ,_day(_day)
    {}
private:
    int _year;
    int _month;
    int _day;
};

//构造函数体赋值
class Date {
public:
    Date(int year, int month, int day) {
        _year = year;
        _month = month;
        _day = day;
    }

private:
    int _year;
    int _month;
    int _day;
};

class A {
public:
    A(int a)
    :_a(a)
    {
        cout << _a << endl;
    }
private:
    int _a;
};
class B {
public:
    B(int a, int ref)
    :_ref(ref)
    ,_n(1)
    ,_x(2)
    ,_aobj(a)
    {}
private:
    A _aobj;
    int& _ref;    //引用
    const int _n; //const成员

    int _x = 1;   //这里的1是缺省值，缺省值是给初始化列表的
};