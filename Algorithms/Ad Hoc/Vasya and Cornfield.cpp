// Codeforces Round #512 - Div 2 B - Vasya and Cornfield
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d; cin >> n >> d;
    int m; cin >> m;
    while (m--) {
        int x, y; cin >> x >> y;
        int dlo = -1, dhi = 1;
        int lo = d, hi = d;
        for (int i = 0; i <= n; i++) {
            if (i==x) {
                if (y>=lo && y<=hi) printf("YES\n");
                else printf("NO\n");
                break;
            }
            lo += dlo;
            hi += dhi;
            if (lo==0) dlo = 1;
            if (hi==n) dhi = -1;
        }
    }
}