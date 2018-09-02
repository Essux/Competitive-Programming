// UVa 13006 - Cake cut
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const ll INF = 1e17 + 17;

struct point {
    ll x, y, value;
    point() {}
    point(int _x, int _y) : x(_x), y(_y) {}
};

ll sum[MAXN];
vector<point> P;
int n;
ll accum;

ll product(point a, point b) {
    return ((a.x * b.y) - (a.y * b.x));
}

ll query(int l, int r) {
    if (l<=r) return (r>0 ? sum[r-1] : 0)- (l>0 ? sum[l-1] : 0)  + product(P[r], P[l]);
    else return sum[n-1] - (l>0 ? sum[l-1] : 0) + (r>0 ? sum[r-1] : 0) + product(P[r], P[l]);
}

ll diff(int l, int r) {
    if (abs(r-l)==1 || abs(l-r)==n-1) return INF;
    return abs(accum-2LL*query(l, r));
}

int main() {
    while (cin >> n) {
        P.clear();
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            P.push_back(point(x, y));
        }

        accum = 0;
        for (int i = 0; i < n; i++) {
            int next = (i+1)%n;
            accum += product(P[i], P[next]);
            sum[i] = accum;
        }

        int i1 = 0, i2 = 2, n2 = 3;
        ll bestDiff = -1, a1 = 0, a2 = 0;
        bool begin = true;
        while (begin || i1!=0) {
            while ((begin || i1!=0) && diff(i1, i2)>=diff(i1, n2)) i2 = n2; n2 = (n2+1)%n;
            while ((begin || i1!=0) && diff(i1, i2)<diff(i1, n2)) {
                if (diff(i1, i2)>=bestDiff) {
                    bestDiff = diff(i1, i2);
                    a1 = max(accum-query(i1, i2), query(i1, i2));
                    a2 = min(accum-query(i1, i2), query(i1, i2));
                }
                i1 = (i1+1)%n;
            }
            begin = false;
        }
        cout << a1 << ' ' << a2 << "\n";
    }
}