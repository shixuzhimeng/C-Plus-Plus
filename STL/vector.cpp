// #include <iostream>
// #include <vector>

// int main() {
//     // 创建一个大小为5，元素初始化为0的vector
//     std::vector<int> v(5, 0);
    
//     // 向vector末尾添加元素
//     v.push_back(10);
//     v.push_back(20);
    
//     // 修改第一个元素
//     v[0] = 100;
    
//     // 输出所有元素
//     std::cout << "Vector elements: ";
//     for (const auto& val : v) {
//         std::cout << val << " ";
//     }
//     std::cout << std::endl;
    
//     // 删除最后一个元素
//     v.pop_back();
    
//     // 输出删除后的元素
//     std::cout << "After pop_back: ";
//     for (const auto& val : v) {
//         std::cout << val << " ";
//     }
//     std::cout << std::endl;
    
//     // 修改vector大小
//     v.resize(3);
//     std::cout << "After resize: ";
//     for (const auto& val : v) {
//         std::cout << val << " ";
//     }
//     std::cout << std::endl;
    
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     vector<int> v1;
//     vector<int> v2{1, 2, 3, 4, 5, 6};
//     vector<int> v3(v2);
//     vector<int> v4(5, 12);
//     vector<int> v5(4);
//     vector<int> v6 = v5;

//     for(int i = 0; i < v1.size(); i++) {
//         cout << v1.at(i);
//     }
//     cout << endl;
//     for(int i = 0; i < v2.size(); i++) {
//         cout << v2.at(i);
//     }
//     cout << endl;
//     for(int i = 0; i < v3.size(); i++) {
//         cout << v3.at(i);
//     }
//     cout << endl;
//     for(int i = 0; i < v4.size(); i++) {
//         cout << v4.at(i);
//     }
//     cout << endl;
//     for(int i = 0; i < v5.size(); i++) {
//         cout << v5.at(i);
//     }
//     cout << endl;
//     for(int i = 0; i < v6.size(); i++) {
//         cout << v6.at(i);
//     }
//     cout << endl;

//     vector<int> v7 = v2;
//     v7.push_back(10);
//     v7.push_back(20);
//     for(int i = 0; i < v7.size(); i++) {
//         cout << v7.at(i);
//     }
//     cout << endl;


//     vector<int> v8 = v2;
//     v8.insert(v8.begin(), 1);
//     v8.insert(v8.end(), 1);
//     v8.insert(v8.end(), 1, 3);
//     v8.insert(v8.end(), v7.begin(), v7.end());
//     for(int i = 0; i < v8.size(); i++) {
//         cout << v8.at(i);
//     }
//     cout << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int main () {
//     //<>中输入要存储数据的类型，
//     vector <int> a;
//     vector <double> b;
//     vector <float> c;

//     vector <int> a(1);
//     vector <int> a(1,1);

//     vector <int> a[2];
//     vector <vector <int>> a;
// }

#include <iostream>
#include <vector>
using namespace std;

// int main () {
//     int n;
//     vector<int> a;
//     int data;
//     for(int i = 0; i < n; i++) {
//         cin >> data;
//         a.push_back(data);
//     }
//     for(int i = 0; i < n; i++) {
//         cout << a[i] << endl;
//     }
//     return 0;
// }
// int main () {
//     //相当于声明了一个迭代器类型的变量it
//     //通俗来说就是声明了一个指针变量
//     int n;
//     vector<int> a;
//     int data;
//     for(int i = 0; i < n; i++) {
//         cin >> data;
//         a.push_back(data);
//     }
//     vector<int>::iterator it = a.begin();
//     for(int i = 0; i < n; i++) {
//         cout << *(it + i) << endl;
//     }
//     for(it = a.begin(); it != a.end(); it++) {
//         cout << *it << endl;
//     }

//     // 1. 输入
//     vector<int> a(n);
//     for (auto &x: a) {
//         cin >> x; // 可以进行输入，注意加引用
//     }
//     // 2. 输出
//     vector<int> v;
//     v.push_back(12);
//     v.push_back(241);
//     return 0;
// }


