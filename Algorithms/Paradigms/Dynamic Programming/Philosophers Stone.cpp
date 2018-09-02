// SPOJ Philosopher's Stone - BYTESM2
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 4;
const int INF = 1<<30;

int h, w;
int arr[MAXN][MAXN], memo[MAXN][MAXN];

int dp (int i, int j) {
    if (j<0 || j>=w) return -INF;
    if (i==h) return 0;
    int &ans = memo[i][j];
    if (ans!=-1) return ans;
    ans = 0;
    for (int k = -1; k <= 1; k++) {
        ans = max(ans, arr[i][j] + dp(i+1, j+k));
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        memset(memo, -1, sizeof(memo));
        cin >> h >> w;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> arr[i][j];
        int ans = 0;
        for (int i = 0; i < w; i++) ans = max(ans, dp(0, i));
        cout << ans << endl;
    }
}