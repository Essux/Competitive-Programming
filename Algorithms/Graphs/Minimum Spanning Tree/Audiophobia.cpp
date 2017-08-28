#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

class UnionFind {
    private:
    vector<int> p, rank;
    public:
    UnionFind(int n) {
        rank.assign(n, 0);
        p.assign(n, 0);
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {return findSet(i) == findSet(j);}
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};


#define MAXN 100 + 10

int N, M, Q;
vector<iii> edgeList;
vector<ii> graph[MAXN];
bool visited[MAXN];

int maxDFS(int u, int obj, int curMax) {
    if (u == obj) return curMax;
    visited[u] = true;
    int ans = -1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].second;
        int w = graph[u][i].first;
        if (!visited[v]) ans = max(ans, maxDFS(v, obj, max(curMax, w)));
    }
    return ans;
}

int main(){
    int ncase = 1;
    while (scanf("%d %d %d", &N, &M, &Q) and not (N==0 and M==0 and Q==0)) {
        if (ncase > 1) printf("\n");
        edgeList = vector<iii>();
        for (int i = 0; i < N; i++) graph[i] = vector<ii>();
        for (int i = 0; i<M; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            edgeList.push_back(iii(w, ii(u, v)));
        }

        sort(edgeList.begin(), edgeList.end());
        UnionFind UF(N);
        for (int i = 0; i < M; i++) {
            int w = edgeList[i].first;
            int u = edgeList[i].second.first;
            int v = edgeList[i].second.second;
            if (!UF.isSameSet(u, v)) {
                graph[u].push_back(ii(w, v));
                graph[v].push_back(ii(w, u));
                UF.unionSet(u, v);
            }
        }

        printf("Case #%d\n", ncase++);
        while (Q--){
            int u, v;
            scanf("%d %d", &u, &v);
            u--, v--;
            fill(visited, visited + N, false);
            int a = maxDFS(u, v, -1);
            if (a == -1) printf("no path\n");
            else printf("%d\n", a);
        }
    }
}