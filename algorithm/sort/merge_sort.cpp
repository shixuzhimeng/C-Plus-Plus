#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int tmp[N];
int n;

void merge_sort(int left, int right) {
    if(left >= right) {
        return ;
    }
    //1.先一分为二
    int mid = (left + right) >> 1;
    //2.先让左右区间有序
    merge_sort(left, mid);
    merge_sort(mid + 1, right);

    //3.合并两个有序数组
    int cur1 = left, cur2 = mid + 1, i = left;
    while(cur1 <= mid && cur2 <= right) {
        if(a[cur1] <= a[cur2]) {
            tmp[i++] = a[cur1++]; 
        }
        else {
            tmp[i++] = a[cur2++];
        }
    }
    //处理剩余元素
    while(cur1 <= mid) {
        tmp[i++] = a[cur1++];
    }
    while(cur2 <= right) {
        tmp[i++] = a[cur2++];
    }

    //替换回去
    for(int i = left; i <= right; i++) {
        a[i] = tmp[i];
    }
}

int main () {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    merge_sort(1, n);
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }


    return 0;
}