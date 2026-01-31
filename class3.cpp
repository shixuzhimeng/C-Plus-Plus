#include <iostream>
#include <stdbool.h>

using namespace std;

// class test {
// private:
//     int _year;
//     int _month;
//     int _day;

// };

// class test2 {
// private:
//     test _year;
// };

// int main() {

//     return 0;
// }

// class Data {
// public:
//     Data(int year = 1, int month = 1, int day = 1) {
//         _year = year;
//         _month = month;
//         _day = day;
//     }
//     //拷贝构造函数
//     Data(const Data& d) {
//         this->_year = d._year;
//         _month = d._month;
//         _day = d._day;
//     }

    // bool operator<(const Data& d) {
    //     if(_year < d._year) {
    //         return true;
    //     }
    //     else if(_year == d._year && _month < d._month) {
    //         return true;
    //     }
    //     else if(_year == d._year && _month == d._month && _day < d._day) {
    //         return true;
    //     }
    //     return false;
    // }


// private:
//     int _year;
//     int _month;
//     int _day;
// };


// // bool operator<(const Data& d1, const Data& d2) {
// //     if(d1._year < d2._year) {
// //         return true;
// //     }
// //     else if(d1._year == d2._year && d1._month < d2._month) {
// //         return true;
// //     }
// //     else if(d1._year == d2._year && d1._month == d2._month && d1._day < d2._day) {
// //         return true;
// //     }
// //     return false;
// // }


// int main() {
//     Data d1(2,2,2);
//     //d1传给了const Data& d
//     //d2传给了this
//     Data d2(d1);
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Date {
// public:
//     Date(int year = 1, int month = 1, int day = 1) {
//         _year = year;
//         _month = month;
//         _day = day;
//     }
//     // void operator=(const Date& d) {
//     //     _year = d._year;
//     //     _month = d._month;
//     //     _day = d._day;
//     // }
//     Date& operator=(const Date& d) {
//         _year = d._year;
//         _month = d._month;
//         _day = d._day;

//         return *this;
//     }
// private:
//     int _year;
//     int _month;
//     int _day;
// };

// int main() {
//     Date d1(2025,1,29);
//     Date d2(2025,1,30);

//     d1 = d2;
//     Date d5, d4;
//     d5 = d4 = d1;
//     Date d2(d1);
// }

#include <iostream>
using namespace std;

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

    Date& operator+=(int day);

    Date& operator++();
    Date& Date::operator++(int);

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