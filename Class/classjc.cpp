#include <iostream>
using namespace std;

// class A {
// public:
//     int a = 0;
// private:
//     int b = 1;
// protected:
//     int c = 2;

// };

// class B : public A {
//     int B = 0;
// };

// class C : private A {
//     int C = 0;
// };

// class D : protected A {
//     int D = 0;
// };

// int main () {

//     return 0;
// }

// class A {
// public:
//     int a = 0;
//     int b = 1;
// };
// class B : public A {
// public:
//     int a = 1;
// };
// int main() {
//     B b1;
//     cout << b1.a << endl;
//     cout << b1.A::a << endl;
// }

// class A {
// public:
//     int a = 0;
// };
// class B {
// public:
//     int b = 1;
// };

// class C : public A , public B {
// public:
//     int c = 2;
// };

// class Base {
// public:
//     Base() { cout << "Base constructor" << endl; }
//     ~Base() { cout << "Base destructor" << endl; }
// };

// class Derived : public Base {
// public:
//     Derived() { cout << "Derived constructor" << endl; }
//     ~Derived() { cout << "Derived destructor" << endl; }
// };

// #include <iostream>
// using namespace std;

// class A {
// public:
//     int a = 10;
// };

// class B : virtual public A{
// public:
//     int b = 20;
// };

// class C : virtual public A{
// public:
//     int c = 30;
// };

// class D : public B ,public C {
// public:
//     int d = 40;
// };

// int main () {
//     D d;
//     d.a = 15;
//     d.a = 36;
//     cout << d.a << endl;
//     cout << d.B::a << endl;
//     cout << d.A::a << endl;
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;

// class Calculator {
// public:
//     int getresult(string oper) {
//         if(oper == "+") {
//             return num1 + num2;
//         }
//         else if(oper == "-") {
//             return num1 - num2;
//         }
//         else if(oper == "*") {
//             return num1 * num2;
//         }
//         else if(oper == "/"){
//             return  num1 / num2;
//         }
//     }

//     int num1;
//     int num2;
// };

// int main () {
//     Calculator c;
//     c.num1 = 5;
//     c.num2 = 1;
//     cout << c.num1 << "+" << c.num2 << "=" << c.getresult("+") << endl; 
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Calculation {
// public:
//     virtual int getresult() {
//         return ;
//     }
//     int num1;
//     int num2;
// };

// class addCalculation : public Calculation {
//     int getresult(){
//         return num1 + num2;
//     }
    
// };
// class delCalculation : public Calculation {
//     int getresult(){
//         return num1 - num2;
//     }
    
// };
// class chengCalculation : public Calculation {
//     int getresult(){
//         return num1 * num2;
//     }
    
// };
// class chuCalculation : public Calculation {
//     int getresult(){
//         return num1 / num2;
//     }
    
// };
// int main() {
//     //加法
//     Calculation *a = new addCalculation;
//     a->num1 = 1;
//     a->num2 = 2;
//     cout << a->num1 << "+" << a->num2 << "=" << endl;
//     delete a;//用完后记得销毁
//     //减法
//     a = new delCalculation;
//     // ...
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class A {
// public:
//     virtual void a(int a) = 0;
// };
// class B : public A {
// public:
//     void a(int a) {
//         a = 10;
//     }
// };

#include <iostream>
using namespace std;

class Drink {
    //煮水
    virtual void Boil() = 0;
    //冲泡
    virtual void Brew() = 0;
    //倒入杯中
    virtual void PourInCup() = 0;
    //加入辅料
    virtual void PutSomething() = 0;
    //制作饮品
    virtual void MakeDrink() {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

class Coffee : public Drink {
public:
    virtual void Boil() {
        cout << "煮水" << endl;
    }
    virtual void Brew() {
        cout << "冲泡" << endl;
    }
    virtual void PourInCup() {
        cout << "倒入杯中" << endl;
    }
    virtual void PutSomething() {
        cout << "加入糖和牛奶" << endl;
    }
};

int main () {
    return 0;
}