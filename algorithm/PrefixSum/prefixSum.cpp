#include <iostream>
using namespace std;
const int N = 1e6 + 10;
long long a[N];
long long b[N];
int main () {
    int x, y;
    cin >> x >> y;
    for(int i = 1; i <= x; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= x; i++) {
        b[i] = b[i - 1] + a[i];
    }
    while(y--) {
        int l, r;
        cin >> l >> r;
        cout << b[r] - b[l - 1] << endl;
    }
}