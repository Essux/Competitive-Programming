// Codeforces Round #478 (Div. 2) - D
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int main() {
    ll n, a, b; cin >> n >> a >> b;
    map<ll, ll> coll;
    map<ii, ll> slope;
    ll ans = 0;
    while (n--) {
        ll x, vx, vy; cin >> x >> vx >> vy;
        ans += coll[a*vx-vy] - slope[ii(vx, vy)];
        coll[a*vx-vy]++;
        slope[ii(vx, vy)]++;
    }
    cout << ans*2 << endl;
}