//SPOJ Is it a tree - PT07Y
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000 + 5;

vector<int> graph[MAXN];
bool visited[MAXN];

void dfs(int u) {
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visited[v]) dfs(v);
    }
}

int main() {
    int n, m; cin >> n >> m;
    bool tree = m==(n-1);
    while (m--) {
        int u, v; cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0);
    for (int i = 0; i < n; i++) tree = tree && visited[i];
    cout << (tree ? "YES" : "NO");
}