#include <string>
#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

#define MAXV 55
#define INF 1000000000

int graph[MAXV][MAXV];
int P, R;

void floyd() {
    for (int k = 0; k < P; k++)
      for (int i = 0; i < P; i++)
        for (int j = 0; j < P; j++)
            graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
}

int main() {
    int network = 1;
    while (cin >> P >> R and P and R) {
        for (int i = 0; i < MAXV; i++)
            for (int j = 0; j < MAXV; j++)
                if (i==j) graph[i][j] = 0;
                else graph[i][j] = INF;
        map<string, int> names;
        int id = 0;
        for (int i = 0; i < R; i++) {
            string a, b;
            cin >> a >> b;
            if (!names.count(a)) names[a] = id++;
            if (!names.count(b)) names[b] = id++;
            int idA = names[a];
            int idB = names[b];
            graph[idA][idB] = 1;
            graph[idB][idA] = 1;
        }
        floyd();
        int maxDist = 0;
        for (int i = 0; i < P; i++)
            for (int j = 0; j < P; j++)
                maxDist = max(maxDist, graph[i][j]);
        printf("Network %d: ", network++);
        if (maxDist>=INF) printf("DISCONNECTED\n");
        else printf("%d\n", maxDist);
        printf("\n");
    }
}