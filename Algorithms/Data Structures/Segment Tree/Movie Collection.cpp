// Kattis - Movie Collection
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

int t[2*MAXN];
int pos[MAXN];
int n, q, sz;

void build() {
    for (int i = 0; i < 2*sz; i++) t[i] = 0;
    for (int i = sz+q; i<2*sz; i++) t[i] = 1;
    for (int i = sz-1; i > 0; i--) t[i] = t[i<<1] + t[i<<1|1];

    for (int i = 0; i < n; i++) pos[i] = q+i;
}

void put(int p, int value) {
    for (t[p+=sz] = value; p > 1; p>>=1) t[p>>1] = t[p] + t[p^1];
}

int query(int r) { //[0, r]
    int l = sz, ans = 0;
    for (r += sz+1; l < r; l>>=1, r>>=1) {
        if (l&1) ans += t[l++];
        if (r&1) ans += t[--r];
    }
    return ans;
}


int main() {
    int tst; cin >> tst;
    while (tst--){
        cin >> n >> q;
        int sp = q-1;
        sz = n+q;
        build();
        while (q--) {
            int a; cin >> a;
            a--;
            cout << query(pos[a]-1) << ' ';
            put(pos[a], 0);
            put(sp, 1);
            pos[a] = sp;
            sp--;
        }
        cout << '\n';
    }
}