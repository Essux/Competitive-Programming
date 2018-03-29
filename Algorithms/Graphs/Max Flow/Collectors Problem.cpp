#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXV 550
#define MAXN 10+2
#define MAXM 25+2
#define N 10
#define M 25
#define INF 1<<30

int res[MAXV][MAXV], mf, f, s, t;
vector<int> p;

int has[MAXN][MAXM]; //Person N has sticker M

void augment(int v, int minEdge) {
    if (v==s) { f = minEdge; return;}
    else if (p[v] != -1) {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}

void debug_bfs(int from) {
    bool visited[MAXV];
    fill(visited, visited+MAXV, false);
    queue<int> q; q.push(from);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        visited[u] = true;
        printf("In cell: %d\n", u);
        for (int i = 0; i < MAXV; i++) {
            if (res[u][i]>0) printf("In %d next %d with %d\n", u, i, res[u][i]);
            if (res[u][i]>0 and !visited[i]) q.push(i);
        }
    }
}

int max_flow() {
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
    return mf;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int ncase = 1; ncase <= T; ncase++) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < MAXN; i++) fill(has[i], has[i]+MAXM, 0);
        for (int i = 0; i < MAXV; i++) fill(res[i], res[i]+MAXV, 0);

        for (int i = 0; i < n; i++) {
            int stickers; scanf("%d", &stickers);
            while (stickers--) {
                int s; scanf("%d", &s);
                has[i][s-1]++;
            }
        }

        //Source and Sink
        s = 526; t = 527;

        //Source to Bob's stickers
        for (int i = 0; i < m; i++) res[s][0*M+i] = INF;

        //Set stickers in res
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i==0) res[i*M+j][i*M+j+250]= has[i][j];
                else res[i*M+j][i*M+j+250]= max(has[i][j]-1, 0);
            }
        }

        //Macronumber to sink
        for (int i = 0; i < M; i++) res[i+500][t] = 1;

        //Numbers to macronumber
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                res[i*M+j+250][j+500] = INF;

        //Macronumbers to others not possesed stickers
        for (int j = 0; j < M; j++)
            for (int k = 0; k < M; k++)
                if (j!=k) res[j+500][0*M+k] = INF;

        for (int i = 1; i<n; i++)
            for (int j = 0; j < M; j++)
                if (has[i][j]==0) res[j+500][i+530] = 1;

        for (int i = 0; i <n; i++)
            for (int j = 0; j < m; j++)
                res[i+530][i*M+j] = INF;

        printf("Case #%d: %d\n", ncase, max_flow());
    }
}