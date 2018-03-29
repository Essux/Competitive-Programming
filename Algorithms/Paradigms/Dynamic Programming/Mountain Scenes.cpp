/*
* Solution to Mountain Scenes (Kattis)
* 0-k Knapsack
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 1e4 + 4;
const int MAXW = 100 + 5;

ll n, w, h;

ll memo[MAXN][MAXW];

ll dp(ll rem, ll id) {
    if (id >= w) return 1;
    if (memo[rem][id]!=-1) return memo[rem][id];
    ll ans = 0;
    for (int i = 0; i <= min(rem, h); i++) {
        ans += dp(rem-i, id+1);
        ans %= MOD;
    }
    return memo[rem][id] = ans;
}

int main() {
    cin >> n >> w >> h;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= w; j++)
            memo[i][j] = -1;
    ll ans = dp(n, 0);
    for (int i = 0; i <= h; i++)
        if (i*w <= n) ans--;
    cout << ans%MOD;
}