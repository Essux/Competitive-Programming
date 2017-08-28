#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, int> dist_node;
typedef pair<int, int> ii;

#define MAXN 1000 + 10

int N, M;
vector<dist_node> graph[MAXN];
vector<int> graphWeighs, mstWeighs;
bool visited[MAXN];
priority_queue<dist_node, vector<dist_node>, greater<dist_node> > q;

void process(int u){
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].second;
        int w = graph[u][i].first;
        if (!visited[v]) q.push(dist_node(w, v));
    }
}


int main(){
    while (scanf("%d %d", &N, &M) and N != 0){
        graphWeighs = vector<int>();
        for (int i = 0; i < N; i++) graph[i] = vector<dist_node>();
        for (int i = 0; i < M; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            graph[u].push_back(dist_node(w, v));
            graph[v].push_back(dist_node(w, u));
            graphWeighs.push_back(w);
        }

        fill(visited, visited + N, false);
        mstWeighs = vector<int>();
        for (int i = 0; i<N; i++){
            if (!visited[i]) {
                process(i);
                while (!q.empty()) {
                    int v = q.top().second;
                    int w = q.top().first;
                    q.pop();
                    if (!visited[v]) {
                        mstWeighs.push_back(w);
                        process(v);
                    }
                }
            }
        }

        sort(graphWeighs.begin(), graphWeighs.end());
        sort(mstWeighs.begin(), mstWeighs.end());
        if (graphWeighs.size() == mstWeighs.size()) {
            printf("forest\n");
        }
        else {
            int i = 0, j = 0;
            bool first = true;

            while (i<graphWeighs.size() and j<mstWeighs.size()){
                if (graphWeighs[i] != mstWeighs[j]) {
                    if (first) printf("%d", graphWeighs[i]);
                    else printf(" %d", graphWeighs[i]);
                    first = false;
                    i++;
                }
                else i++, j++;
            }
            for (int k = i; k < graphWeighs.size(); k++) {
                if (first) printf("%d", graphWeighs[k]);
                else printf(" %d", graphWeighs[k]);
                first = false;
            }
            printf("\n");
        }
    }
}