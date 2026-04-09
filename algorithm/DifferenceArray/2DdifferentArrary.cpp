#include <iostream>
using namespace std;
const int N = 1010;
long long b[N][N];
int n, m, q;
void insert(int x1, int y1, int x2, int y2, long long k) {
    b[x1][y1] += k;
    b[x1][y2 + 1] -= k;
    b[x2 + 1][y1] -= k;
    b[x2 + 1][y2 + 1] += k;
}
int main () {
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            long long x;
            cin >> x;
            insert(i, j, i, j, x);
        }
    }
    while(q--) {
        long long x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        insert(x1, y1, x2, y2, k);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + b[i][j];
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}