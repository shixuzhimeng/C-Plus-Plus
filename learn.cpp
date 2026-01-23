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

namespace use
{
    int rand = 1;
}
int main()
{
    printf("%d", use::rand);
    printf("%p",rand);

    return 0;
}