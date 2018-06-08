//SPOJ ACTIV
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int MAXN = 1e5 + 5;
const int MOD = 1e8;

int n;
vector<ii> arr;
int memo[MAXN];

int dp(int id) {
    if (id>=n) return 1;
    int &cm = memo[id];
    if (cm!=-1) return cm;
    cm = dp(id+1) % MOD;
    vector<ii>::iterator it = lower_bound(arr.begin(), arr.end(), ii(arr[id].second, 0));
    if (it!=arr.end()) cm += dp(it - arr.begin())%MOD;
    else cm++;
    cm %= MOD;
    return cm;
}

int main() {
    while (cin >> n && n!=-1) {
        arr.clear();
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < n; i++) {
            int s, e; cin >> s >> e;
            arr.push_back(ii(s, e));
        }
        sort(arr.begin(), arr.end());
        printf("%08d\n", (dp(0)-1+MOD)%MOD);
    }
}