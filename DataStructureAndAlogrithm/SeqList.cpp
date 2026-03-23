#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int a[N];
int n;

void print() {
    for(int i = 0; i <= n; i++) {
        cout << a[i] << " ";
    }
}

void push_back(int x) {
    a[++n] = x;
}

void push_front(int x) {
    for(int i = n; i >= 1; i++) {
        a[i  + 1] = a[i];
    }
    a[1] = x;
    n++;
}

void push_r(int pos, int x) {
    int i = 0;
    for(int i = n; i >= pos; i++) {
        a[i + 1] = a[i];
    }
    a[pos] = x;
    n++;
}

void pop_back() {
    n--;
}

void pop_front() {
    for(int i = 2; i < n; i++) {
        a[i] = a[i + 1];
    }
    n--;
}

void pop_r(int pos) {
    for(int i = pos; i < n; i++) {
        a[i] = a[i + 1];
    }
    n--;
}

int find(int x) {
    for(int i = 0; i <= n; i++) {
        if(a[i] == x) {
            return i;
        }
    }
    return 0;
}

int find_location(int p) {
    return a[p];
}

void clear() {
    n = 0;
}



class Seqlist {
public:
    Seqlist(){
        n = 0;
    }
    void push_back(int x) {
        a[++n] = x;
    }
    void print() {
        for(int i = 0; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

private:
    int a[N];
    int n;

};
int main () {
    Seqlist s1, s2;
    Seqlist a[N];
    return 0;
}