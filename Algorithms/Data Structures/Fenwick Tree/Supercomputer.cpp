#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 6;

int ft[MAXN];
int n;

int rsq(int b) {
    int sum = 0;
    for (;b; b -= b & (-b)) sum += ft[b];
    return sum;
}

int rsq(int a, int b) {
    return rsq(b) - (a<=1 ? 0 : rsq(a-1));
}

void adjust(int k, int v) {
    for (;k < n+1; k += k & (-k)) ft[k] += v;
}

int main() {
    int q; cin >> n >> q;
    while (q--) {
        char c;
        cin >> c;
        if (c=='F') {
            int i; cin >> i;
            if (rsq(i, i)==1) adjust(i, -1);
            else adjust(i, 1);
        } else {
            int l, r;
            cin >> l >> r;
            cout << rsq(l, r) << endl;
        }
    }
}