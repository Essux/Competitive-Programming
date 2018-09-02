// SPOJ D-query - DQUERY
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int MAXN = 3e5 + 15;
const int MAXQ = 2e5 + 15;
const int MAXA = 1e6 + 15;

class FenwickTree {
    private: vector<int> ft;
    public:
        FenwickTree(int n) {ft.assign(n+1, 0);}
        int rsq(int b){
            if (b==0) return 0;
            int sum = 0;
            for (; b; b -= b & (-b)) sum += ft[b];
            return sum;
        }
        int rsq(int a, int b) {
            return rsq(b) - (a <= 1 ? 0:rsq(a-1));
        }
        void adjust(int k, int v){
            for (; k < (int) ft.size(); k += k & (-k)) ft[k] += v;
        }
};

int arr[MAXN];
vector<ii> qs[MAXN];
int qAns[MAXQ], last[MAXA];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", arr+i+1);
    int q; scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int l, r; scanf("%d %d", &l, &r);
        qs[r].push_back(ii(l, i));
    }

    FenwickTree ft(n);
    for (int i = 1; i <= n; i++) {
        ft.adjust(i, 1);
        //printf("in %d arr %d last %d\n", i, arr[i], last[arr[i]]);
        if (last[arr[i]]>0) ft.adjust(last[arr[i]], -1);
        last[arr[i]] = i;
        for (int j = 0; j < qs[i].size(); j++) {
            int ql = qs[i][j].first;
            int qpos = qs[i][j].second;
            //printf("%d %d: %d-%d\n", ql, i, ft.rsq(i), ft.rsq(ql-1));
            qAns[qpos] = ft.rsq(ql, i);
        }
    }

    for (int i = 0; i < q; i++) printf("%d\n", qAns[i]);
}