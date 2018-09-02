// Educational Codeforces Round 48 - C. Vasya And The Mushrooms
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 3e5 +5;

ll arr[2][MAXN], r[2][MAXN], l[2][MAXN], accuml[2][MAXN], accumr[2][MAXN];

int main() {
    int n; cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            accuml[i][j] = (j>0 ? accuml[i][j-1] : 0) + arr[i][j];
        }
        for (int j = n-1; j >= 0; j--) {
            accumr[i][j] = accumr[i][j+1] + arr[i][j];
            l[i][j] = l[i][j+1] + arr[i][j] * (n-1-j);
            r[i][j] = r[i][j+1] + accumr[i][j];
        }
    }

    ll ans = 0, run = 0;
    for (int i = 0; i < n; i++) {
        ll x = r[i%2][i] + (i*2LL - 1)*accumr[i%2][i];
        ll y = l[(i%2)^1][i] + (2LL*i+n-i)*accumr[(i%2)^1][i];
        ans = max(ans, x+y+run);
        run += arr[i%2][i] * 2LL * i + arr[(i%2)^1][i] * (2LL*i + 1);
    }
    cout << ans << endl;
}