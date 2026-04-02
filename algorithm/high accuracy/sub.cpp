// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// string s1, s2;
// string tmp;

// bool cmp(string a, string b) {
//     if(a.size() != b.size())
//         return a.size() < b.size();
//     return a < b;
// }

// int main() {
//     cin >> s1 >> s2;

//     bool negative = false;
//     if(cmp(s1, s2)) {
//         negative = true;
//         swap(s1, s2);
//     }
    
//     reverse(s1.begin(), s1.end());
//     reverse(s2.begin(), s2.end());
    
//     int borrow = 0; 
    
//     for(int i = 0; i < s1.size(); i++) {
//         int x = s1[i] - '0';
//         int y = (i < s2.size()) ? (s2[i] - '0') : 0;
        
//         x -= borrow;
        
//         if(x < y) {
//             x += 10;
//             borrow = 1;
//         } else {
//             borrow = 0;
//         }

//         tmp += (x - y) + '0';
//     }

//     while(tmp.size() > 1 && tmp.back() == '0') {
//         tmp.pop_back();
//     }

//     reverse(tmp.begin(), tmp.end());
    
//     if(negative && tmp != "0") {
//         cout << "-";
//     }
//     cout << tmp << endl;
    
//     return 0;
// }

#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int a[N], b[N], c[N];
int la, lb, lc;

bool cmp(string& x, string& y) {
    if(x.size() != y.size()) 
        return x.size() < y.size();
    return x < y;
}

void sub(int c[], int a[], int b[]) {
    for(int i = 0; i < lc; i++) {
        c[i] += a[i] - b[i];
        if(c[i] < 0) {
            c[i + 1] -= 1;
            c[i] += 10;
        }
    }
    //处理前导零
    while(lc > 1 && c[lc - 1] == 0) {
        lc--;
    }
}

int main () {
    string x, y;
    cin >> x >> y;
    if(cmp(x, y)) {
        swap(x, y);
        cout << '-';
    }
    la = x.size(), lb = y.size(), lc = max(la, lb);
    for(int i = 0; i < la; i++) {
        a[la - 1 - i] = x[i] - '0'; 
    }
    for(int i = 0; i < lb; i++) {
        b[lb - 1 - i] = y[i] - '0';
    }
    sub(c, a, b);
    for(int i = lc - 1; i >= 0; i--) {
        cout << c[i];
    }
    return 0;
}