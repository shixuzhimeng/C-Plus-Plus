#include <iostream>

using namespace std;

// int main()
// {
//     //这里是错误的
//     //引用过程中，权限不能放大
//     // const int a = 0;
//     // int& b = a; 

//     //可以，没有放大权限，d的改变不影响c
//     // const int c = 10;
//     // int d = c;

//     //不可以
//     //引用过程中，权限可以平移或缩小
//     //z不可以改变但x可以
//     // int x = 10;
//     // int& y = x;
//     // const int& z = x;
//     // ++x;
//     //++z;

//     double dd = 11.11;
//     int ii = dd;
//     //类型转换时产生临时变量
//     const int& rii = dd;
//     //这里给rii的是临时变量，临时变量具有常性

// }

// int Func1() {
//     static int x = 10;
//     return x;
// }

// int& Func2() {
//     static int x = 1;
//     return x;
// }

// int main() {
//     //int& a1 = Func1();//权限放大
//     const int& a2 = Func1();//权限平移

//     int& b1 = Func2();//权限平移
//     const int& b2 = Func2();//权限缩小
//     //但是这两个都是可以的

//     return 0;
// }

// int main() {
//     int a = 10;

//     //语法层面：不开空间，对a取别名
//     int& a1 = a;
//     a1 = 20;

//     //语法层面：开空间，存储a的地址
//     int *a2 = &a;
//     *a2 = 20;

//     return 0;
// }


// int main() {
//     int a = 0;
//     int b = a;

//     auto c = a;  //根据右边的表达式自动推导c的类型

//     auto d = 1+1.1;  //根据右边的表达式自动推导d的类型

//     //typeid()查看变量类型
//     cout << typeid(c).name() <<endl; 
//     cout << typeid(d).name() <<endl; 

//     return 0;
// }

// int main() {
//     int arr[] = {0, 1, 2, 3, 4, 5, 6};

//     for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
//         arr[i] *= 2;

//     for(int *p = arr; p < arr + sizeof(arr) / sizeof(arr[0]); ++p)
//         cout << *p <<  " ";
//     cout << endl;

//     //范围for
//     //适用于数组/容器
//     //依次取数组中数据赋值给e
//     //自动迭代，自动判断结束
//     for(auto e : arr) {
//         cout << e << " ";
//     }
//     cout << endl;


//     //修改数据
//     for(auto& e : arr) {
//         e *= 2;
//     }
//     for(auto e : arr) {
//         cout << e << " ";
//     }
//     cout << endl;


//     return 0;
// }

//内联函数
//适用于短小的频繁调用的函数
//inline对于编译器只是一个建议，最终是否成为inline，编译器自己决定
//1.比较长的函数
//2.递归函数
inline int add(int x, int y) {
    return x + y;
}

int main() {
    for(int i = 0; i < 10000; i++)
    {
        cout << add(i, i+1) << endl;
    }
    return 0;
}