#include <iostream>
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
 
int main() {
    int v;
    while (true){
        vector<int> graph[305];
        cin >> v;
        if (v==0) break;
        int x, y;
        while (true){
            cin >> x >> y;
            if (x==0) break;
            x--;
            y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        cout << ((isBipartite(graph, v)) ? "YES" : "NO") << endl;
    }
}