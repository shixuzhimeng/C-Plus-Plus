#include <iostream>
#include <stdlib.h>
//全局域
//int a = 0;
// 域  命名空间

// namespace test
// {
// 	//局部域
//     int a = 1;
// }

//1.命名空间可以定义变量/函数/类型
// namespace test
// {
//     int a = 0;

//     int add(int a, int b)
//     {
//         return a + b;
//     }

//     struct Node
//     {
//         int val;
//         struct Node* next;
//     }
// }
//2.命名空间可以嵌套
//不同文件的同名的命名空间最后会整合在一起
// namespace A1
// {
// 	int a = 1;
// 	namespace A2
// 	{
// 		int b = 1;
// 	}
// }
// int main()
// {
//     printf("%d\n", A1::a);
//     printf("%d\n", A1::A2::b);
//     return 0;
// }


//局部域->全局域->展开了命名空间 or 指定访问命名空间域
//展开命名空间    展开了就会去访问
//展开命名空间就是编译器是否会在命名空间里去搜索
// using namespace test;

// int main()
// {
//     int a = 2;
//     //域作用限定符::
//     //该符号左边为空代表全局变量
//     printf("%d ", ::a);

//     return 0;
// }

// namespace use
// {
//     int rand = 1;
// }
// int main()
// {
//     printf("%d", use::rand);
//     printf("%p",rand);

//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
	// << 流插入运算符
	cout << "hello world"; 
	//还可以多个
	int x = 1;
	cout << "hello world" << x;
	// 这是换行符 << end1 当然 '\n'也是可以的
	cout << "hello world" << endl << x;	 
}