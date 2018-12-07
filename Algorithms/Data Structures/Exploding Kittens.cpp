// Kattis - Exploding Kittens
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

vector<ii> events;

int main() {
    int n, e, d;
    cin >> n >> e >> d;
    for (int i = 0; i < e; i++) {
        ll a; cin >> a;
        events.push_back(ii(a, -1));
    }
    for (int i = 0; i < d; i++) {
        ll a; cin >> a;
        events.push_back(ii(a, 1));
    }
    sort(events.begin(), events.end());

    vector<ii> pl(n, ii(0, 0));
    for (int i = 0; i < n; i++) pl[i] = ii(0, i);
    ll curt = 0, curp = 0;

    for (int i = 0; i < events.size() && pl.size()>1; i++) {
        ll t = events[i].first;
        ll delta = events[i].second;
        ll nextp = ((t-curt) + curp)% pl.size();
        ll nextval = min(5LL, pl[nextp].first+delta);
        pl[nextp] = ii(nextval, pl[nextp].second);
        if (pl[nextp].first<0) {
            pl.erase(pl.begin()+nextp);
            curp = (nextp-1+pl.size()) % pl.size();
        }
        else curp = nextp;
        curt = t;
    }

    if (pl.size()==1) printf("%d\n", pl[0].second);
    else printf("-1\n");
}