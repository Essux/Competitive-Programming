#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<int> graph[], int v){
    int color[v];
    for (int i = 0; i<v; i++) color[i] = 0;
    queue<int> q;
    q.push(0);
    color[0] = 1;
    while(!q.empty()){
        int curNode = q.front();
        q.pop();
        for (vector<int>::iterator it = graph[curNode].begin(); it != graph[curNode].end(); ++it){
            int nextNode = *it;
            if (color[nextNode] == 0){
                color[nextNode] = 3 - color[curNode];
                q.push(nextNode);
            }
            else if (color[curNode] == color[nextNode]) return false;
        }
    }
    return true;
}

int main(){
    while (true){
        int n;
        scanf("%d", &n);
        if (n==0) break;
        int l;
        scanf("%d", &l);
        vector<int> graph[n];
        while (l--){
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if (isBipartite(graph, n)) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
}