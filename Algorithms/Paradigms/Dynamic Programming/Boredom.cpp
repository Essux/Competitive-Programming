// Codeforces Round 260 Div 1 - A
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

ll f[MAXN], memo[MAXN][2];

ll dp(int id, bool left) {
    if (id<=0 || id>=1e5+1) return 0;
    ll &cm = memo[id][left];
    if (cm!=-1LL) return cm;
    if (left) return cm = max(dp(id-2, left) + id*f[id], dp(id-1, left));
    else return cm = max(dp(id+2, left) + id*f[id], dp(id+1, left));
}

int main() {
    int n; cin >> n;
    memset(f, 0, sizeof(f));
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        f[a]++;
    }
    ll ans = 0;
    for (int i = 1; i <= 1e5; i++)
        ans = max(ans, dp(i, true) + dp(i+2, false));
    cout << ans << endl;
}