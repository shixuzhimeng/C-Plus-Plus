//单向链表的模拟实现
//以下实现的时候默认附带哨兵位
// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int h;
// int id;
// int a[N], b[N];
// int mp[N];

// void push_front(int x) {
//     id++;
//     a[id] = x;
//     mp[x] = id;

//     b[id] = b[h];
//     b[h] = id;
// }

// void print() {
//     for(int i = b[h]; i; i = b[i]) {
//         cout << a[i] << endl;
//     }
//     cout << endl << endl;
// }

// //遍历方法一
// int find(int x) {
//     for(int i = b[h]; i; i = b[i]) {
//         if(a[i] == x) {
//             return i;
//         }
//     }
//     return 0;
// }
// //遍历方法二
// int find(int x) {
//     return mp[x];
// }

// //在pos位置之后插入一个元素
// void insert(int pos, int x) {
//     id++;
//     a[id] = x;
//     b[id] = b[pos];
//     b[pos] = id;
// }
// //删除任意位置之后的元素
// void erase(int pos) {
//     if(b[pos]) {
//         mp[a[b[pos]] = 0];//将pos的下一个位置的元素清空
//         b[pos] = b[b[pos]];//将pos的下一个位置标记为下下一个位置的值
//     }
// }

// int main () {

//     return 0;
// }


// 双向链表的模拟实现
// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;

// int h;
// int id;
// int a[N], pre[N], last[N];
// int mp[N];

// void push_front(int x) {
//     id++;
//     a[id] = x;
//     mp[x] = id;

//     pre[id] = h;
//     last[id] = last[h];
// }

// void print() {
//     for(int i = last[h]; i; i = last[i]) {
//         cout << a[i] << " ";
//     }
//     cout << endl << endl;
// }

// int find(int x) {
//     return mp[x];    
// }

// void insert_back(int pos, int x) {
//     id++;
//     a[id] = x;
//     mp[x] = id;

//     pre[id] = pos;
//     last[id] = last[pos];
// }

// void insert_front(int pos, int x) {
//     id++;
//     a[id] =  x;
//     mp[x] = id;

//     last[pre[pos]] = id;
//     pre[pos] = id;
// }
// //删除下标为pos的值
// void rease(int pos) {
//     mp[a[pos]] = 0;

//     last[pre[pos]] = last[pos];
//     pre[last[pos]] = pre[pos];
// }

// int main () {

//     return 0;
// }
// void insert_back(int pos, int x) {
//     id++;
//     a[id] = x;
//     mp[x] = id;

//     pre[id] = pos;
//     last[id] = last[pos];
// }

// void insert_front(int pos, int x) {
//     id++;
//     a[id] =  x;
//     mp[x] = id;

//     last[pre[pos]] = id;
//     pre[pos] = id;
// }
// //删除下标为pos的值
// void rease(int pos) {
//     mp[a[pos]] = 0;

//     last[pre[pos]] = last[pos];
//     pre[last[pos]] = pre[pos];
// }

// int main () {

//     return 0;
// }


//循环链表的模拟实现
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int a[N];
int b[N];
int h;
int tail;
int id;
int mp[N];

void push_front(int x) {
    id++;
    a[id] = x;
    mp[x] = id;

    b[id] = b[h];
    b[h] = id;

    if(b[id] = h) {
        tail = id;
    }
}

void insert(int pos, int x) {
    id++;
    a[id] = x;
    mp[x] = id;

    b[id] = b[pos];
    b[pos] = id;

    if(pos == tail) {
        tail = id;
    }
}

int main () {

    return 0;
}