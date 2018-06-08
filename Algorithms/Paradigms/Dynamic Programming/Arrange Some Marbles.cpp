#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
vector<ll> cap (4, 0);
ll memo[4][4][8][8][8][8][4][4];

ll dp(ll color, ll sz, vector<ll> c, ll f, ll fsz) {
    if (!c[0] && !c[1] && !c[2] && !c[3] && f!=color && fsz!=sz) {
        if(f!=color && fsz!=sz) return 1LL;
        else return 0LL;
    }
    ll &cur_memo = memo[color][sz][c[0]][c[1]][c[2]][c[3]][f][fsz];
    if (color!=-1 && sz!=-1)
        if (cur_memo!=-1LL) return cur_memo;

    ll ans = 0LL;
    for (ll i = 0; i < 4; i++) {
        if (i == color) continue;
        for (ll j = 1; j < 4; j++) {
            if (j == sz) continue;
            if (c[i] < j) continue;
            vector<ll> c2 = c;
            c2[i] -= j;
            if (color==-1) f = i, fsz = j;
            ans += dp(i, j, c2, f, fsz);
        }
    }
    if (color!=-1 && sz!=-1) cur_memo = ans;
    return ans;
}

int main() {
    ll t; cin >> t;
    memset(memo, -1, sizeof(memo));
    while (t--) {
        cin >> n;
        fill(cap.begin(), cap.end(), 0);
        ll sum = 0;
        for (ll i = 0; i < n; i++) cin >> cap[i], sum += cap[i];
        if (sum==0) cout << "1\n";
        else cout << dp(-1, -1, cap, -1, -1) << endl;
    }
    return (0-0);
}