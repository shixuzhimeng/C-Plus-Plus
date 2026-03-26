#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int h, t; // 队头指针  队尾指针
int q[N];

//入队
void push(int x) {
    q[++t] = x;
}

//出队
void pop() {
    h++;
}

//队头
int top() {
    return q[h + 1];
}

//队尾
int back() {
    return q[t];
}

//判空
int empty() {
    return t == h;
}

//元素的个数
int size() {
    return t - h;
}

int main () {

    return 0;
}