#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN (int) (1e4)
#define D(_x) cout << #_x":" << _x << endl;

vector<int> graph[MAXN];
int dfsCounter;
vector<int> dfsNum, dfsLow, p;
vector<pair<int, int> > bridgeList;

void bridges(int u){
    dfsLow[u] = dfsNum[u] = dfsCounter++;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (dfsNum[v] == -1){
            p[v] = u;

            bridges(v);

            if (dfsLow[v] > dfsNum[u])
                bridgeList.push_back(make_pair(min(u, v), max(v, u)));

            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        }
        else if (v != p[u])
            dfsLow[u] = min(dfsLow[u], dfsNum[v]);
    }
}

int main(){
    int N;
    char trash;
    while (cin >> N){
        for (int i =0; i<N; i++) graph[i] = vector<int>();
        for (int i = 0; i<N; i++){
            int u; cin >> u;
            cin >> trash;

            int e;
            cin >> e >> trash;
            while(e--){
                int v; cin >> v;
                graph[u].push_back(v);
            }
        }

        dfsNum.assign(N, -1);
        dfsLow.assign(N, -1);
        p.assign(N, -1);
        bridgeList = vector<pair<int, int> >();

        dfsCounter = 0;
        for (int i = 0; i < dfsNum.size(); i++)
            if (dfsNum[i] == -1) bridges(i);

        sort(bridgeList.begin(), bridgeList.end());
        printf("%d critical links\n", bridgeList.size());
        for (int i = 0; i < bridgeList.size(); i++) {
            printf("%d - %d\n", bridgeList[i].first, bridgeList[i].second);
        }
        printf("\n");
    }
}