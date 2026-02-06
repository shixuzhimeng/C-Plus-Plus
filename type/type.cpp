#include <iostream>
using namespace std;

template<typename T>
void Swap(T& a, T&b) {
    T tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int a = 10;
    int b = 20;
    double c = 30.30;
    double d = 10.10;
    Swap(a, b);
    Swap(c, d);
}