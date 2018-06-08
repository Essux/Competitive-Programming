// SPOJ Horrible Queries - HORRIBLE
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5;  // limit for array size
int n;  // array size
ll t[2 * N];
int h;
ll d[N];

void init() {
    for (int i = 0; i < n; i++) t[i+n] = 0;
    for (int i = 1; i < n; i++) t[i] = d[i] = 0;
}

void apply(int p, ll value, ll k) {
    t[p] += value*k;
    if (p < n) d[p] += value;
}

void build(int p) {
    ll k = 2;
    while (p > 1) {
        p >>= 1;
        t[p] = t[p<<1] + t[p<<1|1] + d[p]*k;
        k<<=1;
    }
}

void push(int p) {
    ll k = 1<<(h-1);
    for (int s = h; s > 0; --s, k>>=1) {
        int i = p >> s;
        if (d[i] != 0) {
            apply(i<<1, d[i], k);
            apply(i<<1|1, d[i], k);
            d[i] = 0;
        }
    }
}

void inc(int l, int r, ll value) {
    l += n, r += n;
    int l0 = l, r0 = r, k = 1;
    for (; l < r; l >>= 1, r >>= 1, k<<=1) {
        if (l&1) apply(l++, value, k);
        if (r&1) apply(--r, value, k);
    }
    build(l0);
    build(r0 - 1);
}

ll query(int l, int r) {
  l += n, r += n;
  push(l);
  push(r - 1);
  ll res = 0;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
    ll t; cin >> t;
    while (t--) {
        ll m; cin >> n >> m;
        h = sizeof(int) * 8 - __builtin_clz(n);
        init();
        while(m--){
            int op,l, r; cin >> op >> l >> r;
            if (op==0) {
                ll v; cin >> v;
                inc(l-1, r, v);
            } else {
                cout << query(l-1, r) << '\n';
            }
        }
    }
}