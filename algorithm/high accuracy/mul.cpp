// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// string s1, s2;

// int main() {
//     cin >> s1 >> s2;
    
//     // 处理特殊情况
//     if(s1 == "0" || s2 == "0") {
//         cout << "0" << endl;
//         return 0;
//     }
    
//     reverse(s1.begin(), s1.end());
//     reverse(s2.begin(), s2.end());
    
//     int len1 = s1.size();
//     int len2 = s2.size();
    
//     // 修复1：数组大小设为 len1+len2+5，确保不会越界
//     int result[2000] = {0};  // 足够大
    
//     // 逐位相乘
//     for(int i = 0; i < len1; i++) {
//         for(int j = 0; j < len2; j++) {
//             int x = s1[i] - '0';
//             int y = s2[j] - '0';
//             result[i + j] += x * y;
//         }
//     }
    
//     // 处理进位
//     // 修复2：循环到 len1+len2+1，确保处理完所有进位
//     for(int i = 0; i < len1 + len2 + 1; i++) {
//         if(result[i] >= 10) {
//             result[i + 1] += result[i] / 10;
//             result[i] %= 10;
//         }
//     }
    
//     // 修复3：从 len1+len2+1 开始找最高位
//     int pos = len1 + len2 + 1;
//     while(pos >= 0 && result[pos] == 0) {
//         pos--;
//     }
    
//     // 输出结果
//     for(int i = pos; i >= 0; i--) {
//         cout << result[i];
//     }
//     cout << endl;
    
//     return 0;
// }

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;
int a[N], b[N], c[N];
int la, lb, lc;

void mul(int c[], int a[], int b[]) {
    // 1. 逐位相乘
    for(int i = 0; i < la; i++) {
        for(int j = 0; j < lb; j++) {
            c[i + j] += a[i] * b[j];  // 注意：是乘法，且用 +=
        }
    }
    
    // 2. 处理进位
    for(int i = 0; i < la + lb; i++) {
        if(c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    
    // 3. 确定结果长度
    lc = la + lb;
    while(lc > 1 && c[lc - 1] == 0) {
        lc--;
    }
}

int main() {
    string x, y;
    cin >> x >> y;
    
    // 处理零的特殊情况
    if(x == "0" || y == "0") {
        cout << "0" << endl;
        return 0;
    }
    
    la = x.size();
    lb = y.size();
    
    // 反转存储（低位在前）
    for(int i = 0; i < la; i++) {
        a[la - i - 1] = x[i] - '0';
    }
    for(int i = 0; i < lb; i++) {
        b[lb - i - 1] = y[i] - '0';
    }
    
    mul(c, a, b);
    
    // 输出结果（高位在前）
    for(int i = lc - 1; i >= 0; i--) {
        cout << c[i];
    }
    cout << endl;
    
    return 0;
}