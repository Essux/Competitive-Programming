//SPOJ D-query - DQUERY
#include <bits/stdc++.h>

using namespace std;

const int MAXA = 1e6 + 15;
const int MAXN = 3e5 + 15;
const int MAXQ = 2e5 + 15;

int binS;

struct Query {
    int l, r, pos;
    Query(int _l, int _r, int _pos) : l(_l), r(_r), pos(_pos) {}
    Query() {pos = l = r = 0;}
    bool operator < (Query other) const {
        if (l/binS != other.l/binS) return l/binS < other.l/binS;
        return r < other.r;
    }
};

int freq[MAXA], arr[MAXN];
Query qs[MAXQ];
int qAns[MAXQ];

int main() {
    int n; scanf("%d", &n);
    binS = (int) sqrt(n);
    for (int i = 0; i < n; i++) scanf("%d", arr+i+1);
    int q; scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r; scanf("%d %d", &l, &r);
        qs[i] = Query(l, r+1, i);
    }
    sort(qs, qs+q);
    int cl = 0, cr = 0;
    int ccount = 0;
    for (int i = 0; i < q; i++) {
        int l = qs[i].l;
        int r = qs[i].r;
        while (cl < l) {
            freq[arr[cl]]--;
            if (freq[arr[cl]]==0) ccount--;
            cl++;
        }
        while (cl > l) {
            freq[arr[cl-1]]++;
            if (freq[arr[cl-1]]==1) ccount++;
            cl--;
        }
        while (cr < r) {
            freq[arr[cr]]++;
            if (freq[arr[cr]]==1) ccount++;
            cr++;
        }
        while (cr > r) {
            freq[arr[cr-1]]--;
            if (freq[arr[cr-1]]==0) ccount--;
            cr--;
        }
        qAns[qs[i].pos] = ccount;
    }
    for (int i = 0; i < q; i++) printf("%d\n", qAns[i]);
}