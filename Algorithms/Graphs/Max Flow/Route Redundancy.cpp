#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXV 1003
#define INF 1<<30

int res[MAXV][MAXV], mf, f, s, t;
vector<int> p;
vector<pair<int, int> > graph[MAXV];
int flow[MAXV];

void augment(int v, int minEdge) {
    if (v==s) { f = minEdge; return;}
    else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}

int dfs(int u, int minEdge) {
    flow[u] = minEdge;
    if (u == t) return minEdge;
    int best = 0;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].first;
        int w = graph[u][i].second;
        if (min(w, minEdge) <= flow[v]) continue;
        int cand = dfs(v, min(minEdge, w));
        best = max(cand, best);
    }
    return best;
}

int main() {
    int P;
    scanf("%d", &P);
    while (P--) {
        int D, N, E, A, B;
        scanf("%d %d %d %d %d", &D, &N, &E, &A, &B);
        s = A, t = B;
        for (int i = 0; i < MAXV; i++)
            for (int j = 0; j < MAXV; j++)
                res[i][j] = 0;
        for (int i = 0; i < MAXV; i++) graph[i].clear();

        while(E--) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            res[u][v] = w;
            graph[u].push_back(make_pair(v, w));
        }

        fill(flow, flow+MAXV, -1);
        int bestPath = dfs(s, INF);

        mf = 0;
        while (true) {
            f = 0;
            vector<int> dist(MAXV, INF); dist[s] = 0; queue<int> q; q.push(s);
            p.assign(MAXV, -1);
            while(!q.empty()) {
                int u = q.front(); q.pop();
                if (u==t) break;
                for (int v = 0; v < MAXV; v++)
                    if (res[u][v] > 0 && dist[v] == INF)
                        dist[v] = dist[u]+1, q.push(v), p[v] = u;
            }
            augment(t, INF);
            if (f == 0) break;
            mf += f;
        }
        printf("%d %.3f\n", D, (double) mf / (double) bestPath);
    }
}