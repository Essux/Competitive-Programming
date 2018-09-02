//SPOJ Largest Rectangle in a Histogram - HISTOGRA
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
        stack<ii> s;
        ll area = 0;
        for (int i = 0; i < n; i++) {
            ll minI = i;
            while (!s.empty() && s.top().first>a[i]) {
                ll lastA = s.top().first;
                ll lastI = s.top().second;
                area = max(area, lastA * (i-lastI));
                minI = min(minI, lastI);
                s.pop();
            }
            s.push(ii(a[i], minI));
        }
        while (!s.empty()) {
            ll lastA = s.top().first;
            ll lastI = s.top().second;
            area = max(area, lastA * (n-lastI));
            s.pop();
        }

        printf("%lld\n", area);
    }
}