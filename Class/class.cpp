#include <iostream>
using namespace std;

//日期的减
class Date {
public:
    Date(int year = 1, int month = 1, int day = 1) {
        _year = year;
        _month = month;
        _day = day;
    }
    bool operator>(const Date& d);
    bool operator>=(const Date& d);
    bool operator<(const Date& d);
    bool operator<=(const Date& d);
    bool operator==(const Date& d);
    bool operator!=(const Date& d); 

    int GetMonthDay(int year, int month);
    Date& operator+=(int day);
    Date& operator-=(int day);
    int operator-(const Date& d);

    //前置后置
    Date& operator++();
    Date& operator++(int);

    Date& operator--();
    Date& operator--(int);
    
    //可以支持内置类型是库里面实现了
    //可以支持自定义类型是因为函数重载
    //流插入不能写成成员函数
    //Date的对象默认占用第一个参数，写出来的样子不符合习惯
    //但是写为全局就可以
    //void operator<<(ostream& out);
    friend ostream& operator<<(ostream& out, const Date& d);
    friend ostream& operator>>(istream& out, Date& d);

private:
    int _year;
    int _month;
    int _day;
};
bool Date::operator<(const Date& d) {
    if(_year < d._year) {
        return true;
    }
    else if(_year == d._year && _month < d._month) {
        return true;
    }
    else if(_year == d._year && _month == d._month && _day < d._day) {
        return true;
    }
    return false;
}

bool Date::operator==(const Date& d) {
    return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator>=(const Date& d) {
    return !(*this < d);
}

bool Date::operator>(const Date& d) {
    return !(*this <= d);
}

bool Date::operator<=(const Date& d) {
    return *this < d || *this == d; 
}

bool Date::operator!=(const Date& d) {
    return !(*this == d);
} 
int GetMonthDay(int year, int month) {
    static int dayArr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        return 29; 
    } else {
        return dayArr[month];
    }
}
// Date& Date::operator+=(int day) {
//     Date tmp(*this);
//     tmp._day += day;
//     while(tmp._day > GetMonthDay(tmp._year,tmp._month)) {
//         tmp._day -= GetMonthDay(tmp._year,tmp._month);
//         ++tmp._month;
//         if(tmp._month == 13) {
//             ++tmp._year;
//             tmp._month = 1;
//         }
//     }
//     return *this;
// }
Date& Date::operator+=(int day) {
    Date tmp(*this);
    tmp += day;
    return tmp;
}
Date& Date::operator++() {
    *this += 1;
    return *this;
}
//int 仅仅是为了重载
Date& Date::operator++(int) {
    Date tmp = *this;
    *this += 1;

    return tmp;
}
Date& Date::operator-=(int day) {
    if(day < 0) {
        return *this += -day;
    }
    _day -= day;
    while(_day <= 0) {
        --_month;
        if(_month == 0) {
            _month = 12;
            --_year;
        }
        _day += GetMonthDay(_year, _month);

    }
    return *this;
}
Date& Date::operator--() {
    *this -= 1;
    return *this;
}

Date& Date::operator--(int) {
    Date tmp = *this;
    *this -=1;
    return tmp;
}

int Date::operator-(const Date& d) {
    Date max = *this;
    Date min = d;
    int flag = 1;

    if(*this < d) {
        max = d;
        min = *this;
        flag = -1;
    }

    int n = 0;
    while(min != max) {
        ++min;
        ++n;
    }
    return n * flag;
}


// void Date::operator<<(ostream& out) {
//     out << _year << "年" << _month << "月" << _day << "日" << endl;

// }

ostream& operator<<(ostream& out, const Date& d) {
    cout << d._year << d._month << d._day << endl;
    return out;
}

ostream& operator>>(istream& in, Date& d)  {
    in >> d._year >> d._month >> d._day;
    return in;
}

int main() {
    
}