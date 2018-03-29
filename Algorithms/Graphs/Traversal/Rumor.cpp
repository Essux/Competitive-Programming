#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAXN 100004

int arr[MAXN];
vector<int> graph[MAXN];
bool visited[MAXN];

int dfs(int u) {
    visited[u] = true;
    int ans = arr[u];
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visited[v]) ans = min(ans, dfs(v));
    }
    return ans;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", arr+i);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    fill(visited, visited+n+1, false);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) ans += dfs(i);
    }
    cout << ans;
}