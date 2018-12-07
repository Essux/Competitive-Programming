// Kattis - Paintball
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 3;

vector<int> g[MAXN], match, vis, matchl;

int Aug(int l) {
    if (vis[l]) return 0;
    vis[l] = 1;
    for (int j = 0; j < g[l].size(); j++) {
        int r = g[l][j];
        if (match[r]==-1 || Aug(match[r])) {
            match[r] = l;
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int MCBM = 0;
    match.assign(n, -1);
    for (int l = 0; l < n; l++) {
        vis.assign(n, 0);
        MCBM += Aug(l);
    }
    if (MCBM<n) {
        printf("Impossible\n");
        return 0;
    }
    matchl.assign(n, -1);
    for (int r = 0; r < n; r++) {
        matchl[match[r]] = r;
    }
    for (int l = 0; l < n; l++) {
        printf("%d\n", matchl[l]+1);
    }
}