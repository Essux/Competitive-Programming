// Kattis - Supercomputer
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 6;

int n;
int t[2*MAXN];

void modify(int p, int val) {
    for (t[p+=n] = val; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) { //[l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

int main() {
    int q; cin >> n >> q;
    while (q--) {
        char c;
        cin >> c;
        if (c=='F') {
            int i; cin >> i;
            i--;
            if (t[i+n]==1) modify(i, 0);
            else modify(i, 1);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << query(l, r+1) << endl;
        }
    }
}