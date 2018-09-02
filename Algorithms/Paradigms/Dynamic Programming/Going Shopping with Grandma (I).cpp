// UVa 13061 - Going Shopping with Grandma (I)
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e3 + 3;
const ll MOD = 9999959999LL;

ll memo[MAXN][MAXN];

ll dp(int l, int s) {
    if (l == 0) return s+1;
    ll &ans = memo[l][s];
    if (ans!=-1) return ans;
    ans = 1;
    if (s>0) ans += (dp(l, s-1)) % MOD;
    ans %= MOD;
    ans += dp(l-1, s+1);
    return ans = ans % MOD;
}

int main() {
    int l, s;
    memset(memo, -1, sizeof(memo));
    while (cin >> l >> s && (l || s)) {
        cout << dp(l, s) << endl;
    }
}