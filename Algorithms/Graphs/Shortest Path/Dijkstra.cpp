#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <functional>

using namespace std;

#define MAXN 100004
#define INF 1152921504606846976

typedef pair<long long, int> dist_node;

vector<dist_node> graph[MAXN];
long long d[MAXN];
int p[MAXN];

void dijkstra(int n){
    fill(d, d+n+1, INF);
    fill(p, p+n+1, -1);
    priority_queue<dist_node, vector<dist_node>, greater<dist_node> > q;
    q.push(dist_node(0, 0));
    d[0] = 0;
    while (!q.empty()){
        int curNode = q.top().second;
        long long curDistance = q.top().first;
        q.pop();
        if (curDistance > d[curNode]) continue;
        for (int i = 0; i < graph[curNode].size(); i++){
            int nextNode = graph[curNode][i].second;
            long long nextDistance = graph[curNode][i].first;
            if (nextDistance + d[curNode] < d[nextNode]) {
                d[nextNode] = nextDistance + d[curNode];
                p[nextNode] = curNode;
                q.push(dist_node(d[nextNode], nextNode));
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    while (m--){
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        graph[a].push_back(dist_node(w, b));
        graph[b].push_back(dist_node(w, a));
    }
    dijkstra(n);
    vector<int> path;
    int curNode = n-1;
    if (d[n-1] < INF){
        while (curNode != 0){
            path.push_back(curNode);
            curNode = p[curNode];
        }
    }
    path.push_back(0);
    reverse(path.begin(), path.end());
    if (path.size() <= 1)
        cout << -1 << '\n';
    else 
        for (int i = 0; i < path.size(); i++) cout << path[i]+1 << " ";
}