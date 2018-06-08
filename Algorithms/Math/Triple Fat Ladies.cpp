// SPOJ EIGHTS - Triple Fat Ladies
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

const ll MAXN = 1LL<<63;

vector<ll> ans;

int main() {
    int c = 0;
    while (c<1000) {
        if ((c*c*c)%1000 == 888) {
            ans.push_back(c);
        }
        c++;
    }
    int t; cin >> t;
    while (t--) {
        long long k; cin >> k;
        k--;
        ll pref = k/4LL;
        ll suf = k%4LL;
        if (pref != 0) cout << pref;
        cout << ans[suf] << endl;
    }
}