#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXV 30
#define INF 1000000000

int young[MAXV][MAXV], old[MAXV][MAXV];

int V;

int main() {
    while (cin >> V and V) {
        for (int i = 0; i < MAXV; i++)
            for (int j = 0; j < MAXV; j++){
                int val = (i==j) ? 0 : INF;
                young[i][j] = val;
                old[i][j] = val;
            }

        for (int i = 0; i < V; i++) {
            char y, u, from, to; int w;
            cin >> y >> u >> from >> to >> w;
            from -= 'A'; to -= 'A';
            if (y=='Y') {
                if (u=='B') young[to][from] = min(young[to][from], w);
                young[from][to] = min(w, young[from][to]);
            }
            else {
                if (u=='B') old[to][from] = min(w, old[to][from]);
                old[from][to] = min(w, old[from][to]);
            }
        }
        char me, miguel; cin >> me >> miguel;
        me -= 'A'; miguel -= 'A';

        for (int k = 0; k < MAXV; k++)
          for (int i = 0; i < MAXV; i++)
            for (int j = 0; j < MAXV; j++)
              young[i][j] = min(young[i][j], young[i][k] + young[k][j]);


        for (int k = 0; k < MAXV; k++)
          for (int i = 0; i < MAXV; i++)
            for (int j = 0; j < MAXV; j++)
              old[i][j] = min(old[i][j], old[i][k] + old[k][j]);

        int curMin = INF;
        vector<int> places;
        for (int i = 0; i < MAXV; i++) {
            int next = young[me][i]+old[miguel][i];
            if (next < curMin) {
                curMin = next;
                places.clear(); places.push_back(i);
            }
            else if (next==curMin) places.push_back(i);
        }
        if (curMin>=INF) printf("You will never meet.\n");
        else {
            printf("%d", curMin);
            for (int i =0; i < places.size(); i++) printf(" %c", places[i]+'A');
            printf("\n");
        }
    }
}