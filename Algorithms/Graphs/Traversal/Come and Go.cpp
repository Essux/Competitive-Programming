#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 2000 + 5

int N, M;
int dfsCount, numSCC;
vector<int> graph[MAXN];
vector<int> dfsNum, dfsLow, S;
vector<bool> visited;

void SCC(int u){
    dfsLow[u] = dfsNum[u] = dfsCount++;
    S.push_back(u);
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (dfsNum[v] == -1) SCC(v);
        if (visited[v])
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
    }
    // printf("In Node %d\n", u+1);
    // printf("Out Degree: %d\n", graph[u].size());
    // printf("Low: %d Num: %d\n", dfsLow[u], dfsNum[u]);
    if (dfsLow[u] == dfsNum[u]) {
        numSCC++;
        while(true){
            int v = S.back(); S.pop_back();
            visited[v] = false;
            if (v == u) break;
        }
    }
}


int main(){
    while (scanf("%d %d", &N, &M) and N != 0 and M != 0){
        for (int i = 0; i < N; i++) graph[i] = vector<int>();
        while (M--){
            int u, v, bi;
            scanf("%d %d %d", &u, &v, &bi);
            u--; v--;
            graph[u].push_back(v);
            if (bi == 2) graph[v].push_back(u);
        }
        dfsLow.assign(N, -1);
        dfsNum.assign(N, -1);
        visited.assign(N, false);
        S = vector<int>();
        dfsCount = numSCC = 0;

        for (int i = 0; i < N; i++) if (dfsNum[i] == -1) SCC(i);

        printf("%d\n", numSCC==1);
    }
}