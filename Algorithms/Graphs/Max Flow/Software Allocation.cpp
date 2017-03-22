#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>

using namespace std;

#define INF 1<<30
#define MAX_V 40
 
int mf,
    f,
    s = 10,
    t = 11,
    res[MAX_V][MAX_V];

vector <int> p;
 
void augment(int v, int minEdge){  
    if (v == s){ f = minEdge; return ;}
    else if ( p[v] != -1){
        augment(p[v],min(minEdge,res[p[v]][v]));
        res[p[v]][v] -=f; res[v][p[v]]+=f;
    }
}
 
 
int main(){
    string line;
    while (cin.good()){
        for (int i = 0; i < MAX_V; i++){
            for (int j = 0; j < MAX_V; j++){
                res[i][j] = 0;
            }
        }

        int neededApps = 0;
        while (getline(cin, line) && line.size()>1){
            char program = line[0];
            res[s][program - 53] = line[1] - 48;
            neededApps += line[1] - 48;
            for (int i = 3; i < line.size() && line[i]!=';'; i++){
                res[program - 53][line[i] - 48] = 1;
            }
        }

        //Conectando PCs al sumidero
        for (int i = 0; i < 10; i++) res[i][t] = 1;

        mf = 0;
        while (true){
        f = 0;
        vector <int> dist(MAX_V, INF);
        dist[s] = 0; queue<int> q; q.push(s);
        p.assign(MAX_V,-1);
        while(!q.empty()){
            int u = q.front();q.pop();
            if (u == t) break;
            for (int v = 0; v < MAX_V; v++)
                if (res[u][v] > 0 && dist[v] == INF)
                    dist[v] = dist[u] + 1, q.push(v), p[v] = u;
        }
        augment(t,INF);
        if (f == 0) break;
        mf += f;
        }

        if (neededApps > mf) printf("!\n");
        else {
            for (int i = 0; i < 10; i++){
                int j = 12;
                while (res[i][j] == 0 && j < 38) j++;
                if (j == 38) printf("_");
                else printf("%c", j+53);
            }
            printf("\n");
        }
   }
}