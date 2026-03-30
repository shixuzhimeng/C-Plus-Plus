#include <iostream>
#include <vector>
using namespace std;

//实现方法一
//vector模拟
// const int N = 1e5 + 10;
// int a[N];
// int n;
// vector<int> edges[N];//存储树


// int main () {
//     cin >> n;
//     for(int i = 1; i < n; i++) {
//         int a, b;
//         cin >> a >> b;
//         edges[a].push_back(b);
//         edges[b].push_back(a);
//     }
//     return 0;
// }

//实现方法二
//链式前向星
const int N = 1e5 + 10;
int h[N], e[N * 2], ne[N * 2], id;
int n;

void add(int a, int b) {
    id++;
    e[id] = b;
    ne[id] = h[a];
    h[a] = id;
}

int main () {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        add(a,b);
        add(b,a);
    }
    return 0;
}

//vector模拟下的DFS
//当前遍历到U这棵子树
// bool st[N];
// void DFS(int u) {
//     //访问该节点
//     cout << u << " ";
//     st[u] = true;

//     //访问他的子树
//     for(auto v : edges[u]) {
//         if(!st[u]) {
//             DFS(v);
//         }
//     }
// }

//链式前向星下的DFS
// bool st[N];
// void DFS(int u) {
//     cout << u << " ";
//     st[u] == true;
//     for(int i = h[u]; i; i = ne[i]) {
//         int v = e[i];
//         if(!st[v]) {
//             DFS(v);
//         }
//     }
// }


//vector模拟下的BFS
//在BFS下的遍历的时候需要队列辅助
//  1.根结点先入队
//  2.若队列不为空那么先将队头节点出队，然后将其子结点入队
//  3.重复此过程，直到队列为空
// #include <queue>
// bool st[N];
// void BFS() {
//     queue<int> q;
//     q.push(1);

//     st[1] = true;
//     while(q.size()) {
//         int u = q.front();
//         q.pop();
//         cout << u << " ";
        
//         for(auto v : edges[u]) {
//             if(!st[v]) {
//                 q.push(v);
//                 st[v] = true;
//             }
//         }
//     }
// }

//链式前向星下的BFS
#include  <queue>
bool st[N];
void BFS() {
    queue<int> q;
    q.push(1);
    st[1] = true;
    while (q.size()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int i = h[u]; i; i= ne[i]) {
            int v = e[i];
            if(!st[v]) {
                q.push(v);
                st[v] = true;
            }
        }
    }
}
