#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define D(_x) cout << #_x": " << _x << endl;

#define MAX_V 320
#define MAXN 102
const int INF = 1<<30;

typedef vector<int> vi;

int res[MAX_V][MAX_V], mf, f, s = 302, t = 304, x = 303, o = 301;
vi p;
vi adjList[MAX_V];
vi parents[MAXN];

void augment(int v, int minEdge){
    if (v == s){ f = minEdge; return ;}
    else if ( p[v] != -1){
        augment(p[v],min(minEdge,res[p[v]][v]));
        res[p[v]][v] -=f; res[v][p[v]]+=f;
    }
}

void max_flow() {
    mf = 0;
    while (1) {
        f = 0;
        bitset<MAX_V> vis; vis[s] = true;
        queue<int> q; q.push(s);
        p.assign(MAX_V, -1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u==t) break;
            for (int j = 0; j < adjList[u].size(); j++) {
                int v = adjList[u][j];
                if (res[u][v] > 0 && !vis[v])
                    vis[v] = true, q.push(v), p[v] = u;
            }
        }
        augment(t, INF);
        if (f == 0) break;
        mf += f;
    }
}

void addEdge(int u, int v, int w) {
    res[u][v] = w;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

int main() {
    int n, q;
    while (cin >> n >> q) {
        for (int i = 0; i < MAXN; i++) parents[i].clear();
        for (int i = 0; i < MAX_V; i++) adjList[i].clear();
        for (int i = 0; i < MAX_V; i++)
            for (int j = 0; j < MAX_V; j++)
                res[i][j] = 0;

        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            while (k--) {int a; cin >> a; parents[i].push_back(a);}
        }
        while (q--) {
            //Cleaning
            for (int i = 0; i < MAX_V; i++) adjList[i].clear();
            for (int i = 0; i < MAX_V; i++)
                for (int j = 0; j < MAX_V; j++)
                    res[i][j] = 0;

            int k; cin >> k;
            vector<int> son_alleles;
            for (int i = 0; i < k; i++) {
                int v; cin >> v;
                son_alleles.push_back(v);
            }
            //Graph construction
            for (int i = 0; i < n; i++) {
                addEdge(s, i, 1);
                addEdge(i, i+100, 1);
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < parents[i].size(); j++) {
                    int v = parents[i][j];
                    addEdge(i+100, v+200-1, 1);
                }
                if ((int) parents[i].size() < n) {
                    addEdge(i+100, o, 1);
                }
            }
            for (int i = 0; i < son_alleles.size(); i++) {
                int v = son_alleles[i];
                addEdge(v+200-1, t, 1);
                addEdge(v+200-1, x, INF);
            }
            int extras = n - (int) son_alleles.size();
            addEdge(x, t, extras);
            addEdge(o, x, extras);

            /*for (int i = 0; i < MAX_V; i++) {
                for (int j = 0; j < MAX_V; j++) {
                    if (res[i][j]) printf("%d -> %d [%d]\n", i, j, res[i][j]);
                }
            }*/
            max_flow();

            cout << (mf == n ? "Y\n" : "N\n");
        }
    }
}