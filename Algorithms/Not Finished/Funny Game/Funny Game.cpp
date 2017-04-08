#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[1003];
bool visited[1003];
bool doiwin[1003];

void bfs(vector<int> graph[], int start){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int currNode = q.front();
        q.pop();
        visited[currNode] = true;
        cout << currNode << endl;
        //Are there any more neighbours there?
        int neighbours = 0;
        for (int i = 0; i<graph[currNode].size(); i++){
            int nextNode = graph[currNode][i];
            if(!visited[nextNode]){
                q.push(nextNode);
                neighbours++;
            }
        }
        if (neighbours==0) 
    }
}

int minimax(){
    
}

int main(){
    int v, start;
    cin >> v >> start;
    int n = v;
    while(--n){
        int f, t;
        cin >> f >> t;
        graph[f].push_back(t);
        graph[t].push_back(f);
    }
    bfs(graph, start);
}