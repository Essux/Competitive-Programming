#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

#define Dl(_x) printf(#_x":%d\n", _x);

#define MAXN 3*100000 + 5
#define INF 1<<30

typedef pair<int, int> uv;

vector<int> graph[MAXN];
int policeStat[MAXN];
bool visited[MAXN];
map<uv, int> indexMap;
set<uv> removedEdges;
int n, k, d;
vector<int> policeCities;
int dist[MAXN];

void bfs(){
    queue<int> q;
    for (int i = 0; i< policeCities.size(); i++) {
        policeStat[policeCities[i]] = policeCities[i];
        q.push(policeCities[i]);
        dist[policeCities[i]] = 0;
    }
    while (!q.empty()){
        int curNode = q.front(); q.pop();
        
        for (int i = 0; i < graph[curNode].size(); i++){
            int nextNode = graph[curNode][i];
            if (dist[curNode] <= d and dist[nextNode] > dist[curNode] +1 and policeStat[nextNode] == -1){
                dist[nextNode] = dist[curNode] + 1;
                policeStat[nextNode] = policeStat[curNode];
                q.push(nextNode);
            }
            else if (policeStat[nextNode] !=  policeStat[curNode]){
                removedEdges.insert(uv(min(curNode, nextNode), max(curNode, nextNode)));
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &n, &k, &d);

    for (int i = 0; i< n; i++) policeStat[i] = -1;
    for (int i = 0; i< n; i++) visited[i] = false;
    int p;
    for (int i = 0; i < k; i++) {
        scanf("%d", &p); 
        p--;
        policeCities.push_back(p);
        policeStat[p] = p;
    }
    for (int i = 0; i < n-1; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        indexMap[uv(min(u, v), max(u, v))] = i;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; i++) dist[i] = INF;
    bfs();

    printf("%d\n", removedEdges.size());
    for (set<uv>::iterator it = removedEdges.begin(); it!=removedEdges.end(); it++){
        printf("%d ", indexMap.find(*it)->second+1);
    }
}