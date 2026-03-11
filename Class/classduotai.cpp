#include <iostream>
using namespace std;

class Animal {
public:
    // 虚函数 
    virtual void speak () {
        cout << "动物在说话" << endl;
    }
};

class cat : public Animal{
public:
    //重写  函数返回值类型 函数名 参数列表 完全相同
    //重写（override）基类的虚函数
    void speak () {
        cout << "猫在说话" << endl;
    }
};

class dog :public Animal{
public:
    void speak () {
        cout << "狗在说话" << endl;
    }
};

void Dospeak(Animal &animal) {
    animal.speak();
}

int main () {
    cat Cat;
    dog Dog;

    Dospeak(Cat);
    Dospeak(Dog);

    return 0;
}