#include <iostream>
using namespace std;

//这是最早的写法
//template<class Td>
//这是后来的写法
// template<typename T>
// void Swap(T& a, T&b) {
//     T tmp = a;
//     a = b;
//     b = tmp;
// }

// int main() {
//     int a = 10;
//     int b = 20;
//     double c = 30.30;
//     double d = 10.10;
//     Swap(a, b);
//     Swap(c, d);

//     return 0;
// }
// template <typename T1, typename T2>
// void P (const T1& a, const T2& b) {
//     cout << a + b <<endl;
// }

// template <class T>
// class test {
// public:
//     Stack() {
//         _array = new T[capacity];
//         _capacity = capacity;
//         _size = 0;
//     }
    
// private:
//     T* _array;
//     int _capacity;
//     int _size;
// };

// int main() {
//     test<int> t1;
//     test<double> t2;
// }