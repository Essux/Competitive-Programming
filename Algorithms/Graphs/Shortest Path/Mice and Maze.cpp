#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

#define MAXN 103
#define INF 1<<30

typedef pair<int, int> dist_node;

vector<dist_node> graph[MAXN];
vector<int> dist(MAXN, INF);

void dijkstra(int s, int n){
    dist.assign(MAXN, INF);
    dist[s] = 0;
    priority_queue <dist_node, vector<dist_node>, greater<dist_node> > q;
    q.push(dist_node(0, s));
    while (!q.empty()){
        int curD = q.top().first;
        int curNode = q.top().second; q.pop();
        if (curD > dist[curNode]) continue;
        for (int i = 0; i < (int) graph[curNode].size(); i++){
            int nextDist = graph[curNode][i].first;            
            int nextNode = graph[curNode][i].second;       
            if (dist[curNode] + nextDist < dist[nextNode]){
                dist[nextNode] = dist[curNode] + nextDist;
                q.push(dist_node(dist[nextNode], nextNode));
            }
        }
    }
}

int main(){
    int cases;
    cin >> cases;
    while (cases--){
        int n, start, t, e;
        for (int i = 0; i <= n; i++) graph[i].clear();
        cin >> n >> start >> t >> e;
        start--;        
        while (e--){
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            graph[v].push_back(dist_node(w, u));
        }
        dijkstra(start, n);
        int count = 0;
        for (int i = 0; i < n; i++) if (dist[i]<=t) count++;
        printf("%d\n", count);
        if (cases>0) printf("\n");
    }
}