// SPOJ PT07X - Vertex Cover
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 5;
const int INF = 1e9;

vector<int> g[MAXN];
int memo[MAXN][3];

int dp(int u, int mode, int p) {
    if (g[u].size()==1 && g[u][0]==p) return mode;

    int &ans = memo[u][mode];
    if (ans!=-1) return ans;

    ans = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v!=p) ans += dp(v, 0, u);
    }

    if (mode == 0) {
        int alt = 0;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (v!=p) alt += dp(v, 1, u);
        }
        return ans = min(ans, alt);
    }
    return ans;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0, -1) << endl;
}