#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

bool visited[10003], is_on[10003];
vector<int> topo_sort;

void dfs(vector<int> graph[], int node){
    visited[node] = true;
    for(int i = 0; i< (int) graph[node].size(); i++){
        int nextNode = graph[node][i];
        if(!visited[nextNode]) dfs(graph, nextNode);
    }
    topo_sort.push_back(node);
}

void turn_lights(vector<int> graph[], int node){
    is_on[node] = true;
    for(int i = 0; i< (int) graph[node].size(); i++){
        int nextNode = graph[node][i];
        if(!is_on[nextNode]) turn_lights(graph, nextNode);
    }
}

int main(){
    int t, total;
    cin >> t;
    total = t;
    while(t--){
        for(int i = 0; i < 10003; i++){
            visited[i] = false;
            is_on[i] = false;
        }
        int n, m;
        cin >> n >> m;
        vector<int> graph[n];
        while(m--){
            int u, v;
            cin >> u;
            cin >> v;
            u--;
            v--;
            graph[u].push_back(v);
        }
        for (int i = 0; i < n; i++) if (!visited[i]) {
            dfs(graph, i);
        }
        reverse(topo_sort.begin(), topo_sort.end());
        int count = 0;
        for (int i = 0; i < topo_sort.size(); i++) {
            if (!is_on[topo_sort[i]]) {
                turn_lights(graph, topo_sort[i]);
                count++;
            }
        }
        cout << "Case " << total - t << ": " << count << endl;
        topo_sort.clear();
    }
}