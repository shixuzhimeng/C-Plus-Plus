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

#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v1;
    vector<int> v2{1, 2, 3, 4, 5, 6};
    vector<int> v3(v2);
    vector<int> v4(5, 12);
    vector<int> v5(4);
    vector<int> v6 = v5;

    for(int i = 0; i < v1.size(); i++) {
        cout << v1.at(i);
    }
    cout << endl;
    for(int i = 0; i < v2.size(); i++) {
        cout << v2.at(i);
    }
    cout << endl;
    for(int i = 0; i < v3.size(); i++) {
        cout << v3.at(i);
    }
    cout << endl;
    for(int i = 0; i < v4.size(); i++) {
        cout << v4.at(i);
    }
    cout << endl;
    for(int i = 0; i < v5.size(); i++) {
        cout << v5.at(i);
    }
    cout << endl;
    for(int i = 0; i < v6.size(); i++) {
        cout << v6.at(i);
    }
    cout << endl;

    vector<int> v7 = v2;
    v7.push_back(10);
    v7.push_back(20);
    for(int i = 0; i < v7.size(); i++) {
        cout << v7.at(i);
    }
    cout << endl;


    vector<int> v8 = v2;
    v8.insert(v8.begin(), 1);
    v8.insert(v8.end(), 1);
    v8.insert(v8.end(), 1, 3);
    v8.insert(v8.end(), v7.begin(), v7.end());
    for(int i = 0; i < v8.size(); i++) {
        cout << v8.at(i);
    }
    cout << endl;

    return 0;
}