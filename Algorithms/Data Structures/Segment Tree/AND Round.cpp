// Solution to SPOJ - ANDROUND
#include <cstdio>
#include <vector>

using namespace std;

#define MAXN 22004

int arr[MAXN];

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
        for (int i = 0; i < n; i++) t[i+n] = arr[i];
        for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] & t[i<<1|1];
    }

    void modify(int p, int value) {  // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
    }

    int query(int l, int r) {  // sum on interval [l, r)
        int res = -1;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res &= t[l++];
            if (r&1) res &= t[--r];
        }
        return res;
    }

    int circular_query(int l, int r) {
        if (l < r) return query(l, r+1);
        return query(0, r+1) & query(l, n);
    }
};

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k; scanf("%d %d", &n, &k);
        for (int i = 0; i < n; i++) scanf("%d", arr+i);
        SegmentTree st(n);
        if (n<=2*k+1) {
            for (int i = 0; i < n; i++) {
                if (i>0) printf(" ");
                printf("%d", st.query(0, n));
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                int r = (i + k) % n;
                int l = (i + n - k) % n;
                if (i>0) printf(" ");
                printf("%d", st.circular_query(l, r));
            }
        }
        printf("\n");
    }
}