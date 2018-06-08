// SPOJ Can you answer these queries I - GSS1
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5;  // limit for array size
const int INF = 1<<30;
int n;  // array size

struct Node {
    ll maxPref, maxSuff, total, ans;
    Node (ll maxPref_, ll maxSuff_, ll total_, ll ans_) : maxPref(maxPref_), maxSuff(maxSuff_), total(total_), ans(ans_) {}
    Node () {}
    void print() {
        printf("pref %lld suff %lld total %lld ans %lld\n", maxPref, maxSuff, total, ans);
    }
};
Node t[2 * N];

Node mergeNodes(Node l, Node r) {
    if (l.maxPref==-INF) return r;
    if (r.maxPref==-INF) return l;
    Node cur;
    cur.maxPref = max(l.maxPref, l.total+r.maxPref);
    cur.maxSuff = max(r.maxSuff, r.total+l.maxSuff);
    cur.total = l.total + r.total;
    cur.ans = max(max(l.ans, r.ans), l.maxSuff + r.maxPref);
    return cur;
}

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) {
        Node l = t[i<<1];
        Node r = t[i<<1|1];
        t[i] = mergeNodes(l, r);
    }
}

Node query(int l, int r) {  // sum on interval [l, r)
  Node ansLeft (-INF, 0, 0, 0);
  Node ansRight (-INF, 0, 0, 0);
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) ansLeft = mergeNodes(ansLeft, t[l++]);
    if (r&1) ansRight = mergeNodes(t[--r], ansRight);
  }
  return mergeNodes(ansLeft, ansRight);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;  scanf("%d", &a);
        t[i+n] = Node(a, a, a, a);
    }
    build();
    ll m; scanf("%lld", &m);
    while (m--) {
        int l, r; scanf("%d %d", &l, &r);
        l--, r--;
        printf("%lld\n", query(l, r+1).ans);
    }
}