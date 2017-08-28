#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

#define MAXN 100 + 4

int N;
map<string, int> StoI;
string ItoS[MAXN];
bool visited[MAXN];
vector<int> order;
vector<int> graph[MAXN];
int indegree[MAXN];

typedef pair<int, int> deep_appear;

class Comparison {
    public:
    bool operator() (deep_appear a, deep_appear b) {
        if (a.second < b.second) return false;
        if (a.second > b.second) return true;   
        return a.first > b.first;
    }
};

void toposort(){
    priority_queue<deep_appear, vector<deep_appear>, Comparison > q;
    for (int i = 0; i<N; i++)
        if (indegree[i] == 0) q.push(deep_appear(0, i));
    while(!q.empty()){
        int cur = q.top().second; 
        int deep = q.top().first;
        q.pop();
        order.push_back(cur);
        for (int i = 0; i<graph[cur].size(); i++){
            int next = graph[cur][i];
            indegree[next]--;
            if (indegree[next] == 0) q.push(deep_appear(deep+1, next));
        }
    }
}

int main(){
    int ncase = 1;
    while (cin >> N){
        StoI = map<string, int>();
        fill(ItoS, ItoS + N, "");
        memset(indegree, 0, sizeof indegree);
        for (int i = 0; i < N; i++){
            string drink;
            cin >> drink;
            StoI[drink] = i;
            ItoS[i] = drink;
        }
        for (int i = 0; i<MAXN; i++) graph[i] = vector<int>();
        int M; scanf("%d", &M);
        while (M--){
            string B1, B2;
            cin >> B1 >> B2;
            int n1, n2;
            n1 = StoI[B1];
            n2 = StoI[B2];
            graph[n1].push_back(n2);
            indegree[n2]++;
        }

        memset(visited, false, sizeof visited);
        order = vector<int>();
        toposort();
        printf("Case #%d: Dilbert should drink beverages in this order:", ncase++);
        for (int i = 0; i<N; i++)
            cout << ' ' << ItoS[order[i]];
        printf(".\n\n");
    }
}