#include <iostream>
using namespace std;

//缺省参数
// void Func(int a = 0)
// {
//     cout << a << endl;
// }

// int main()
// {
//     Func();//没有传参时，使用默认参数
//     Func(10);//传参时，用指定参数

//     return 0;
// }

//函数重载
// int Add(int a, int b)
// {
//     cout << "int Add(int a, int b)" << endl;
//     return a + b;
// }

// double Add(double a, double b)
// {
//     cout << "double Add(int a, int b)" << endl;
//     return a + b;
// }

// int main()
// {
//     cout << Add(1,2) << endl;
//     cout << Add(1.1, 2.2) << endl;

//     return 0;
// }

// void test()
// {
//     cout << "1+1" << endl;
// }

// void test(int a, int b)
// {
//     cout << a + b << endl;
// }

void test(char a, int b)
{
	cout << a << b << endl;
}
void test(int a, char b)
{
	cout << a << b << endl;
}