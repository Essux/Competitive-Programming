// Greetings! (Kattis)

#include <bits/stdc++.h>

using namespace std;

#define D(_x) cout << #_x":" << _x << endl;

typedef long long ll;

const int MAXN = 15+1;

int n, k;
ll w[MAXN], h[MAXN], q[MAXN];
ll waste[1<<MAXN], memo[1<<MAXN][MAXN];

void fill_waste() {
    for (int mask = (1<<n)-1; mask >= 0; mask--) {
        ll maxW = -1, maxH = -1;
        for (int i = 0; i < n; i++) {
            if (mask & (1<<i)) {
                maxH = max(maxH, h[i]);
                maxW = max(maxW, w[i]);
            }
        }
        ll wst = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1<<i)) {
                wst += ((maxH*maxW)-(h[i]*w[i]))*q[i];
            }
        }
        waste[mask] = wst;
    }
}

ll dp(int mask, int i) {
    if (memo[mask][i]!=-1) return memo[mask][i];
    if (mask == 0 || i==1) return waste[mask];

    ll ans = 1LL<<62;
    for (int sub = mask; sub > 0; sub = (sub-1) & mask) {
        ans = min(ans, waste[sub] + dp(mask - sub, i-1));
    }

    return memo[mask][i] = ans;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> h[i] >> q[i];
    }
    k = min(k, n);
    for (int i = 0; i < (1<<MAXN); i++) {
        for (int j = 0; j < MAXN; j++) {
            memo[i][j] = -1;
        }
    }
    fill_waste();
    cout << dp((1<<n)-1, k) << endl;
}