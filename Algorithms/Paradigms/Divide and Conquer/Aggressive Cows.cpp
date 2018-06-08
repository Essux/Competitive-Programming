#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int n, c;
int a[MAXN];

bool can(int x) {
    int cur = a[0], visC = 1;
    for (int i = 1; i < n; i++) {
        if (a[i]-cur>=x) visC++, cur = a[i];
    }
    return visC>=c;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> c;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);
        int l = 1, r = a[n-1]-a[0]+1;
        while (r-l>1) {
            int m = (l+r)/2;
            bool canM = can(m);
            if (canM) l = m;
            else r = m;
        }
        cout << l << endl;
    }
}