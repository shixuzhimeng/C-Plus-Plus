#include <iostream>
using namespace std;
const int N = 1e6 + 10;
long long a[N];
long long b[N];
int main () {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    while(m--) {
        long long l, r, k;
        cin >> l >> r >> k;
        b[l] += k, b[r + 1] -= k;
    }
    for(int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + b[i];
        cout << b[i] << " ";
    }
    return 0;
}