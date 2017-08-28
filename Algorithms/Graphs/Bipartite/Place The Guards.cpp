#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 200 + 4
#define INF 1<<30

vector<int> graph[MAXN];
int color[MAXN];
int v;
bool isBipartite;

int bipartiteMin(int u){
    queue<int> q;
    q.push(u);
    color[u] = 1;
    int col1 = 1, col0 = 0;
    while (!q.empty() and isBipartite){
        int cur = q.front(); q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (color[next] == -1){
                if (color[cur] == 0) col1++;
                else col0++;
                color[next] = 1 - color[cur];
                q.push(next);
            }
            if (color[next] == color[cur]){
                isBipartite = false;
                break;
            }
        }
    }
    if (min(col0, col1) == 0) return max(col0, col1);
    return min(col0, col1);
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        int e;
        scanf("%d %d", &v, &e);
        while (e--){
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        fill(color, color + v, -1);

        int ans = 0;
        isBipartite = true;
        for (int i = 0; i < v and isBipartite; i++)
            if (color[i] == -1) ans += bipartiteMin(i);
        if (isBipartite) printf("%d\n", ans);
        else printf("-1\n");
        for (int i = 0; i < v; i++) graph[i] = vector<int>();
    }
}
