#include <bits/stdc++.h>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

#define INF 1<<30
#define MAX_V 40
 
int mf,
    f,
    s = 0,
    t = 1,
    res[MAX_V][MAX_V]; 

vector <int> p;

void augment(int v, int minEdge){  
    if (v == s){ f = minEdge; return ;}
    else if ( p[v] != -1){
        augment(p[v],min(minEdge,res[p[v]][v]));
        res[p[v]][v] -=f; res[v][p[v]]+=f;
    }
}
 
int sizeToN (string size){
    if (size == "XXL") return 2;
    else if (size == "XL") return 3;
    else if (size == "L") return 4;
    else if (size == "M") return 5;
    else if (size == "S") return 6;
    else if (size == "XS") return 7;
    else return -1;
}

int main(){
    int cases;
    cin >> cases;
    while (cases--){
        for (int i = 0; i < MAX_V; i++){
            for (int j = 0; j < MAX_V; j++){
                res[i][j] = 0;
            }
        }

        int shirts, persons;
        cin >> shirts >> persons;
        for (int i = 2; i <= 7; i++) res[s][i] = shirts / 6;
        for (int i = 0; i < persons; i++){
            string sizeA, sizeB;
            cin >> sizeA >> sizeB;
            res[sizeToN(sizeA)][i+8] = 1;
            res[sizeToN(sizeB)][i+8] = 1;
            res[i+8][t] = 1;
        }

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
        cout << (mf >= persons ? "YES":"NO") << '\n';
    }
}