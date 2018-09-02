#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef set<ii>::iterator setit;

const int MAXN = 100000 + 10;

ll a[MAXN];

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) scanf("%lld", a+i);
        set<ii> s;
        ll area = 0;
        for (int i = 0; i < n; i++) {
            ll minI = i;
            setit lim = s.upper_bound(ii(a[i], n));
            for (setit it = lim; it!=s.end(); it++)
                area = max(area, it->first*(i-it->second)),
                minI = min(minI, it->second);
            s.erase(lim, s.end());
            s.insert(ii(a[i], minI));
        }
        for (setit it = s.begin(); it!=s.end(); it++)
            area = max(area, it->first*(n-it->second));

        printf("%lld\n", area);
    }
}