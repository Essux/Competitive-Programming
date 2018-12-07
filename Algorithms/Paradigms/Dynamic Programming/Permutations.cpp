// SPOJ PERMUT1 - Permutations
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 12 + 2;
const int MAXK = 100;

int n;
int memo[1<<MAXN][MAXK];

int dp(int mask, int k) {
    if (k<0) return 0;
    bitset<MAXN> bs (mask);
    if (bs.count()==n) return k==0;

    int &ans = memo[bs.to_ulong()][k];
    if (ans != -1) return ans;

    int inv = 0;
    ans = 0;
    for (int i = n-1; i >= 0; i--) {
        if (!bs[i]) {
            bs[i] = true;
            ans += dp(bs.to_ulong(), k-inv);
            bs[i] = false;
        } else inv++;
    }

    return ans;
}

int main() {
    int t, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        memset(memo, -1, sizeof(memo));
        cout << dp(0, k) << endl;
    }
}