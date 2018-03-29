#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define D(_x) cout << #_x":" << _x << endl;

typedef pair<int, int> ii;

const int MAXN = 1e5 + 10;

vector<int> graph[MAXN];
bool visited[MAXN];

int bfs(int node) {
    queue<ii> q;
    q.push(ii(node, 1));
    int maxAns = 1;
    while (!q.empty()) {
        int u = q.front().first;
        int depth = q.front().second;
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            q.push(ii(v, depth+1));
        }
        maxAns = max(maxAns, depth);
        visited[u] = true;
    }
    return maxAns;
}

int main() {
    int t; scanf("%d", &t);
    for (int ncase = 1; ncase <= t; ncase++) {
        int n, e; cin >> n >> e;
        for (int i = 0; i < n; i++) graph[i] = vector<int>();
        fill(visited, visited+n+1, false);
        while (e--) {
            int u, v; cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
        }
        int maxAns = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) maxAns = max(maxAns, bfs(i));
        }
        printf("Case %d: %d\n", ncase, maxAns);
    }
}