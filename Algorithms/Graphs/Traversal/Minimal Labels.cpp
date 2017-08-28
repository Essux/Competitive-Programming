#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

#define MAXN (int) 10e5 + 4

vector<int> graph[MAXN], order;
bool visited[MAXN];
int position[MAXN], outdegree[MAXN];
int N, M;

void toposort() {
    priority_queue<int> q;
    for (int i = 0; i < N; i++)
        if (outdegree[i] == 0) q.push(i);
    int index = N;
    while (!q.empty()) {
        int cur = q.top();
        q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (--outdegree[next] == 0) q.push(next);
        }
        order.push_back(cur);
        position[cur] = index--;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    fill(outdegree, outdegree + N, 0);
    while (M--) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        graph[v].push_back(u);
        outdegree[u]++;
    }
    toposort();

    for (int i = 0; i < N; i++)
        printf("%d ", position[i]);
}