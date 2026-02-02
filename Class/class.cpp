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
    
    int GetMonthDay(int year, int month);
    Date& operator+=(int day);
    Date& operator-=(int day);

private:
    int _year;
    int _month;
    int _day;
};
int GetMonthDay(int year, int month) {
    static int dayArr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
        return 29; 
    } else {
        return dayArr[month];
    }
}
Date& Date::operator+=(int day) {
    Date tmp(*this);
    tmp._day += day;
    while(tmp._day > GetMonthDay(tmp._year,tmp._month)) {
        tmp._day -= GetMonthDay(tmp._year,tmp._month);
        ++tmp._month;
        if(tmp._month == 13) {
            ++tmp._year;
            tmp._month = 1;
        }
    }
    return *this;
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

int main() {
    
}