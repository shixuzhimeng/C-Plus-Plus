#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int stk[N];
int n;

//进栈
void push(int x) {
    stk[++n] = x;
}

//出栈
void pop() {
    n--;
}

//栈顶
int top() {
    return stk[n];
}

//判空
int empty() {
    return n == 0;
}

//有效元素的个数
int size() {
    return n;
}

int main () {

    return 0;
}