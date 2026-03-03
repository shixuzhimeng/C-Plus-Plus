#include <iostream>
#include <vector>

int main() {
    // 创建一个大小为5，元素初始化为0的vector
    std::vector<int> v(5, 0);
    
    // 向vector末尾添加元素
    v.push_back(10);
    v.push_back(20);
    
    // 修改第一个元素
    v[0] = 100;
    
    // 输出所有元素
    std::cout << "Vector elements: ";
    for (const auto& val : v) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    // 删除最后一个元素
    v.pop_back();
    
    // 输出删除后的元素
    std::cout << "After pop_back: ";
    for (const auto& val : v) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    // 修改vector大小
    v.resize(3);
    std::cout << "After resize: ";
    for (const auto& val : v) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    return 0;
}