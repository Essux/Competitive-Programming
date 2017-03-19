#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

#define MAXN 20005
#define INF 1<<30

typedef pair<int, int> dist_node;

vector<dist_node> graph [MAXN];
int d[MAXN];

void dijkstra(int s, int n){
    for (int i = 0; i<=n; i++) d[i] = INF;
    priority_queue <dist_node, vector<dist_node>, greater<dist_node> > q;
    d[s] = 0;
    q.push(dist_node(0, s));
    while (!q.empty()){
        int curDist = q.top().first;
        int curNode = q.top().second;
        q.pop();
        if (curDist > d[curNode]) continue;
        for (int i = 0; i < graph[curNode].size(); i++){
            int nextNode = graph[curNode][i].second;
            int extra_w = graph[curNode][i].first;
            if (d[curNode] + extra_w < d[nextNode]){
                d[nextNode] = d[curNode] + extra_w;
                q.push(dist_node(d[nextNode], nextNode));
            }
        }
    }
}

int main(){
    int n, ntemp;
    cin >> n;
    ntemp = n;
    while (ntemp--){
        int v, e, s, t;
        for (int i = 0; i<=v; i++) graph[i].clear();
        cin >> v >> e >> s >> t;
        while (e--){
            int a, b, w;
            cin >> a >> b >> w;
            graph[a].push_back(make_pair(w, b));
            graph[b].push_back(make_pair(w, a));
        }
        dijkstra(s, v);
        printf("Case #%d: ", n-ntemp);
        if (d[t] == INF) printf("unreachable\n");
        else printf("%d\n", d[t]);
    }
}