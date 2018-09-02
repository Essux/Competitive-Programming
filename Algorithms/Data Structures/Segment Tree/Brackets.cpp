// SPOJ Brackets - BRCKTS
#include <bits/stdc++.h>

using namespace std;

struct Bracket {
    int remOp, remCl;
    Bracket(int _remOp, int _remCl) : remOp(_remOp), remCl(_remCl) {}
    Bracket() {}
    void print() {
        printf("Op %d Cl %d\n", remOp, remCl);
    }
};

const int MAXN = 30000 + 10;

int n;
string s;
Bracket t[2*MAXN];

Bracket merge (Bracket l, Bracket r) {
    int del = min(l.remOp, r.remCl);
    return Bracket(r.remOp + l.remOp - del, l.remCl + r.remCl - del);
}

void build () {
    for (int i = 0; i < n; i++) t[i+n] = Bracket(s[i]=='(', s[i]==')');
    for (int i = n-1; i > 0; i--) t[i] = merge(t[i<<1], t[i<<1|1]);
}

void modify(int p) {
    t[p += n] = Bracket(1-t[p].remOp, 1-t[p].remCl);
    for (; p > 1; p>>=1) t[p>>1] = merge(t[p&(~1)], t[p|1]);
}

bool query() {
    Bracket ansL(0, 0), ansR(0, 0);
    for (int l = n, r = 2*n; l < r; l>>=1, r>>=1) {
        if (l&1) ansL = merge(ansL, t[l++]);
        if (r&1) ansR = merge(t[--r], ansR);
    }
    Bracket ans = merge(ansL, ansR);
    return (ans.remOp == 0) && (ans.remCl == 0);
}

int main() {
    int ncase = 1;
    while (cin >> n) {
        cin >> s;
        build();
        int q; cin >> q;
        printf("Test %d:\n", ncase++);
        while (q--) {
            int a; cin >> a;
            if (a==0) cout << (query() ? "YES":"NO") << '\n';
            else modify(a-1);
        }
    }
}