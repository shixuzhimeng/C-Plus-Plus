#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int main() {
//     int x = 7;
//     float y = 3.0;

//     auto p = [x,y](int a, int b)->float{
//         return x*y + a*b;
//     };
//     cout << p(10, 20);
// }

// 输出221


// int main() {
//     vector<int> a{1, 9, 10, 0, 3, 7, 16};
//     sort(a.begin(), a.end(), [](float a, float b){return a < b;});
//     for(auto b : a) {
//         cout << b << " ";
//     }
//     return 0;
// }

// 按值对比按引用捕获
// int main() {
//     int x = 7;
//     float y = 3.0;

//     auto p = [&x, &y](int a, int b)->float{
//         return x*y + a*b;
//     };

//     cout << p(10, 20) << endl;
    
//     y += 1.5;
//     cout << p(10, 20) << endl;
//     return 0;
// }

int main () {
    int x = 7;
    float y = 3.0;
    float z = -1;
    auto p = [=, &y](int a, int b)->float{
        return x*y + a*b;
    };
    cout << p(10, 20);
    return 0;
}