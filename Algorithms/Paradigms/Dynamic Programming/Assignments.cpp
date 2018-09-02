// SPOJ Assignments - ASSIGN
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 20 + 2;

int n;
bool likes[MAXN][MAXN];
ll memo[1<<MAXN];

ll dp (int mask) {
    int id = n - __builtin_popcount(mask);
    if (id>=n) return (mask==0);
    ll &ans = memo[mask];
    if (ans!=-1) return ans;
    ans = 0;
    for (int i = 0; i < n; i++)
        if (likes[id][i] && (mask & (1<<i))) ans += dp(mask & ~(1<<i));
    return ans;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int mask = 1<<n;
        while (mask>=0) memo[mask--] = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int a;
                scanf("%d", &a);
                likes[i][j] = (a==1);
            }

        printf("%lld\n", dp((1<<n)-1));
    }
}