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

#include <iostream>
#include <stdexcept>

template <typename T>
class SimpleVector {
private:
    T* data;
    size_t size;
    size_t capacity;

    void resize(size_t newCap) {
        T* newData = new T[newCap];
        for (size_t i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCap;
    }

public:
    SimpleVector() : data(nullptr), size(0), capacity(0) {}

    ~SimpleVector() { delete[] data; }

    void push_back(const T& val) {
        if (size >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = val;
    }

    T& operator[](size_t index) {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    size_t getSize() const { return size; }
};

int main() {
    SimpleVector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    for (size_t i = 0; i < vec.getSize(); ++i)
        std::cout << vec[i] << " ";
    return 0;
}