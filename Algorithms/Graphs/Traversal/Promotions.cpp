#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 5003
#define D(_x) cout << #_x": " << _x << '\n';

vector<int> graph[MAXN], rev_graph[MAXN];
int visited[MAXN], rev_visited[MAXN];
int iter = 0;

int dfs(int u) {
    visited[u] = iter;
    int child = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (visited[v] != iter) child += dfs(v);
    }
    return child;
}

int rev_dfs(int u) {
    rev_visited[u] = iter;
    int rev_child = 1;
    for (int i = 0; i < rev_graph[u].size(); i++) {
        int v = rev_graph[u][i];
        if (rev_visited[v] != iter) rev_child += rev_dfs(v);
    }
    return rev_child;
}

int main() {
    int a, b, e, p;
    while (cin >> a >> b >> e >> p) {
        for (int i = 0; i < e; i++) {
            graph[i].clear();
            rev_graph[i].clear();
        }
        while (p--) {
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
            rev_graph[v].push_back(u);
        }

        int rA = 0, rB = 0, rC = 0;
        for (int i = 0; i < e; i++) {
            iter++;
            int includeNeed = e - dfs(i) + 1;
            iter++;
            int excludeNeed = rev_dfs(i) - 1;
            if (a >= includeNeed) rA++;
            if (b >= includeNeed) rB++;
            if (b <= excludeNeed) rC++;
        }

        printf("%d\n%d\n%d\n", rA, rB, rC);
    }
}