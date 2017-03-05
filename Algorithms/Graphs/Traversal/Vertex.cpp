#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXN 104

bool visited[MAXN];

void dfs(vector<int> graph[], int u){
    for (int i = 0; i<graph[u].size(); i++){
        int nextNode = graph[u][i];
        if (!visited[nextNode]){
            visited[nextNode] = true;
            dfs(graph, nextNode);
        }
    }
}

int main(){
    int n;
    while (cin >> n && n!=0){
        int u;
        vector<int> graph[n];
        while (cin >> u && u!=0){
            u--;
            int v;
            while (cin >> v && v!=0){
                v--;
                graph[u].push_back(v);
            }
        }
        int searches;
        cin >> searches;
        while (searches--){
            int from;
            cin >> from;
            from--;
            for (int i = 0; i < MAXN; i++) visited[i] = false;
            dfs(graph, from);
            vector<int> inaccesible;
            for (int i = 0; i < n; i++) if (!visited[i]) {
                inaccesible.push_back(i+1);
            }
            cout << inaccesible.size();
            for (int i = 0; i <inaccesible.size(); i++) cout << " " <<inaccesible[i];
            cout << endl; 
        }
    }
}