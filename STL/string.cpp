#include <iostream>
using namespace std;

// int main() {
//     string s1;
//     string s2("name");
//     string s3("hello world");
//     string s4(10,'*');
//     string s5(s2);
//     string s6(s3, 6, 5);
//     string s7(s3, 6);
// }

// int main() {
//     //增
//     string s1("hello");
//     //尾插一个字符
//     //s1.push_back(' ');
//     //尾插一个字符串
//     //s1.append("world");

//     s1 += ' ';
//     s1 += "world";

//     cout << s1 << endl;
//     return 0;
// }

// int main() {
//     size_t x = 0;
//     cin >> x;

//     //将x转成string对象
//     string xstr;
//     while (x) {
//         size_t val = x % 10;
//         xstr += ('0' + val);
//         x /= 10;
//     }

//     //逆置

// }

// int main() {
//     string s1("hello world");
//     string s0;

//     //遍历
//     cout << s1.size() << endl;

//     for(size_t i = 0; i < s1.size(); i++) {
//         cout << s1[i];
//     }
//     cout << endl;
//     s1[0]--;

//     //下标+[]
//     for(size_t i = 0; i < s1.size(); i++) {
//         cout << s1[i];
//     }
//     cout << endl;
//     char s3[] = "hello world";
//     s3[1]++;    //->*(s3+1)
//     s1[1]++;    //s1.opertor[](1)
//     return 0;
// }

// int main() {
//     string s1("hello world");

//     string::iterator it = s1.begin();
//     while(it != s1.end()) {
//         //写
//         (*it)--;

//         ++it;
//     }
//     cout << endl;

//     string::iterator it = s1.begin();
//     while(it != s1.end()) {
//         //读
//         cout << *it << " ";
//         ++it;
//     }
//     cout << endl;

//     for(auto& ch : s1) {
//         ch++;
//     }
//     cout << endl;


//     for(char ch : s1) {
//         cout << endl;
//     }
//     cout << endl;

//     return 0;
// }

// int main() {
//     reverse(v.begin(), v.end());
//     for(auto e : v) {
//         cout << e << " ";
//     }


//     return 0;
// }

// int main () {
//     string s1("hello world");
//     //string::reserve_iterator rit = s1.rbegin();
//     auto rit = s1.rbegin();
//     while(rit != s1.rend()) {
//         cout << *rit << " ";
//         ++rit;
//     }
//     cout << endl;
//     return 0;
// }

// int main() {
//     string s1("haha");
//     cout << s1.size() << endl;
//     cout << s1.length() << endl;
//     cout << s1.max_size() << endl;
//     cout << s1.capacity() << endl;
//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

// int main() {
//     // 创建字符串
//     string str1 = "Hello";
//     string str2("World");
//     string str3(5, 'A');  // "AAAAA"
    
//     cout << str1 << endl;     // Hello
//     cout << str2 << endl;     // World
//     cout << str3 << endl;     // AAAAA
    
//     // 获取长度
//     cout << str1.length() << endl;     // 5
//     cout << str1.size() << endl;       // 5 (与length相同)
//     cout << str1.capacity() << endl;   // 当前分配的内存大小
    
//     // 访问字符
//     cout << str1[0] << endl;           // H
//     cout << str1.at(1) << endl;        // e
//     cout << str1.front() << endl;      // H (C++11)
//     cout << str1.back() << endl;       // o (C++11)
    
//     return 0;
// }
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = "World";
    
    // 方法1：使用 + 运算符
    string s3 = s1 + " " + s2;
    cout << s3 << endl;  // Hello World
    
    // 方法2：使用 append()
    string s4 = s1;
    s4.append(" ");
    s4.append(s2);
    cout << s4 << endl;  // Hello World
    
    // 方法3：使用 +=
    string s5 = s1;
    s5 += " ";
    s5 += s2;
    cout << s5 << endl;  // Hello World
    
    // 连接字符和数字
    string s6 = "Number: ";
    s6 += to_string(42);
    cout << s6 << endl;  // Number: 42
    
    return 0;
}