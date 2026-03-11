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

#include <iostream>
using namespace std;

class A {
public:
    int a = 10;
};

class B : virtual public A{
public:
    int b = 20;
};

class C : virtual public A{
public:
    int c = 30;
};

class D : public B ,public C {
public:
    int d = 40;
};

int main () {
    D d;
    d.a = 15;
    d.a = 36;
    cout << d.a << endl;
    cout << d.B::a << endl;
    cout << d.A::a << endl;
    return 0;
}