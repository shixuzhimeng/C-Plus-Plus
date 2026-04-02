// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// string s1, s2;
// string tmp;

// int main () {
//     cin >> s1 >> s2;
//     reverse(s1.begin(), s1.end());
//     reverse(s2.begin(), s2.end());

//     int maxlen = max(s1.size(), s2.size());
//     int carry = 0;

//     for(int i = 0; i < maxlen || carry; i++) {
//         int sum = carry;
        
//         if(i < s1.size()) {
//             sum += s1[i] - '0';
//         }
//         if(i < s2.size()) {
//             sum += s2[i] - '0';
//         }
        
//         tmp += (sum % 10) + '0';
//         carry = sum / 10; 
//     }
    
//     reverse(tmp.begin(), tmp.end());
//     cout << tmp << endl;

//     return 0;
// }


#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int a[N], b[N], c[N];
int la, lb, lc;
void add (int c[], int a[], int b[]) {
    for(int i = 0; i < lc; i++) {
        c[i] += a[i] + b[i];//对应位相加
        c[i + 1] += c[i] / 10;// 处理进位
        c[i] %= 10;//处理本位
    }
    if(c[lc]) {
        lc++;
    }
}

int main () {
    string x, y;
    cin >> x >> y;
    la = x.size(), lb = y.size(), lc = max(la, lb);
    for(int i = 0; i < la; i++) {
        a[la - 1 - i] = x[i] - '0'; 
    }
    for(int i = 0; i < lb; i++) {
        b[lb - 1 - i] = y[i] - '0';
    }
    add(c, a, b);

    for(int i = lc - 1; i >= 0; i--) {
        cout << c[i];
    }
    return 0; 
}