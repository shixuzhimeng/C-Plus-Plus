#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <pthread.h>

// 随机数生成器
std::vector<int> generateRandomData(size_t n) {
    std::vector<int> data(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 1000000);
    for (auto& x : data) x = dist(gen);
    return data;
}

bool isSorted(const std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i)
        if (vec[i-1] > vec[i]) return false;
    return true;
}

std::vector<int> singleThreadSort(const std::vector<int>& data) {
    std::vector<int> sorted = data;
    std::sort(sorted.begin(), sorted.end());
    return sorted;
}


// 传递给线程的参数结构体
struct ThreadParam {
    const std::vector<int>* data;   // 原始数据指针
    size_t start;                   // 子数组起始索引
    size_t end;                     // 子数组结束索引
    std::vector<int> result;        // 线程排序后的结果
};

// 线程工作函数
void* sortSubarray(void* arg) {
    ThreadParam* param = static_cast<ThreadParam*>(arg);
    // 拷贝子数组
    std::vector<int> sub(param->data->begin() + param->start,
                         param->data->begin() + param->end);
    std::sort(sub.begin(), sub.end());
    param->result = std::move(sub);   // 将结果存回参数结构体
    return nullptr;
}

// 多线程排序
std::vector<int> parallelSortPthread(const std::vector<int>& data, size_t numThreads) {
    size_t n = data.size();
    if (n == 0) return {};
    if (numThreads <= 1) return singleThreadSort(data);

    // 1. 分割数据范围
    std::vector<std::pair<size_t, size_t>> ranges;
    size_t partSize = n / numThreads;
    size_t remainder = n % numThreads;
    size_t start = 0;
    for (size_t i = 0; i < numThreads; ++i) {
        size_t end = start + partSize + (i < remainder ? 1 : 0);
        ranges.emplace_back(start, end);
        start = end;
    }

    // 2. 准备线程参数和线程数组
    std::vector<ThreadParam> params(numThreads);
    std::vector<pthread_t> threads(numThreads);

    // 3. 创建线程，每个线程负责排序一个子数组
    for (size_t i = 0; i < numThreads; ++i) {
        params[i].data = &data;
        params[i].start = ranges[i].first;
        params[i].end = ranges[i].second;
        pthread_create(&threads[i], nullptr, sortSubarray, &params[i]);
    }

    // 4. 等待所有线程完成
    for (size_t i = 0; i < numThreads; ++i) {
        pthread_join(threads[i], nullptr);
    }

    // 5. 收集排序后的子数组
    std::vector<std::vector<int>> sortedParts;
    for (auto& param : params) {
        sortedParts.push_back(std::move(param.result));
    }

    // 6. 两两归并
    std::vector<int> result = std::move(sortedParts[0]);
    for (size_t i = 1; i < sortedParts.size(); ++i) {
        std::vector<int> merged;
        merged.reserve(result.size() + sortedParts[i].size());
        std::merge(result.begin(), result.end(),
                   sortedParts[i].begin(), sortedParts[i].end(),
                   std::back_inserter(merged));
        result = std::move(merged);
    }
    return result;
}