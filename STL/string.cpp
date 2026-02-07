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

int main() {
    string s1("hello world");

    string::iterator it = s1.begin();
    while(it != s1.end()) {
        //写
        (*it)--;

        ++it;
    }
    cout << endl;

    string::iterator it = s1.begin();
    while(it != s1.end()) {
        //读
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    for(auto& ch : s1) {
        ch++;
    }

    for(char ch : s1) {
        cout << endl;
    }
    cout << endl;

    return 0;
}