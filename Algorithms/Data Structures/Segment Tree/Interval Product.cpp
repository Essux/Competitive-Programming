// Solution to UVa - Interval Product
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

#define MAXN 100004

int arr[MAXN];

int standarize(int a) {
    if (a > 0) return 1;
    if (a < 0) return -1;
    return a;
}

class SegmentTree{
    int n;
    vector<int> t;

    public:
    SegmentTree(int size){
        n = size;
        t.assign(2*n, 0);
        build();
    }

    void build() {
        for (int i = 0; i < n; i++) t[i+n] = standarize(arr[i]);
        for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] * t[i<<1|1];
    }

    void modify(int p, int value) {  // set value at position p
        for (t[p += n] = standarize(value); p > 1; p >>= 1) t[p>>1] = t[p] * t[p^1];
    }

    int query(int l, int r) {  // sum on interval [l, r)
        int res = 1;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res *= t[l++];
            if (r&1) res *= t[--r];
        }
        return res;
    }
};

int main() {
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        for (int i = 0; i < n; i++) scanf("%d", arr+i);
        SegmentTree st(n);
        while (k--) {
            string com; cin >> com;
            if (com=="C") {
                int i, v; scanf("%d %d", &i, &v);
                st.modify(i-1, v);
            }
            else {
                int i, j; scanf("%d %d", &i, &j);
                int ans = st.query(i-1, j);
                if (ans > 0) printf("+");
                else if (ans < 0) printf("-");
                else printf("0");
            }
        }
        printf("\n");
    }
}