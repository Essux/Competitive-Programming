#include <bits/stdc++.h>
#include <string>
#include <cstdio>
#include <cctype>
#include <map>

using namespace std;

#define INF 1<<30
#define MAXV 60

int mf, f, s = 26, t = 27, res[MAXV][MAXV];

vector<int> p;
map<char, string> names[26];

void augment(int v, int minEdge){  
    if (v == s){ f = minEdge; return ;}
    else if ( p[v] != -1){
        augment(p[v],min(minEdge,res[p[v]][v]));
        res[p[v]][v] -=f; res[v][p[v]]+=f;
    }
}

int main(){
    int cases, tcases;
    cin >> cases;
    tcases = cases;
    while (cases--){
        /* Cleaning */
        for (int i = 0; i < MAXV; i++){
            for(int j = 0; j < MAXV; j++){
                res[i][j] = 0;
            }
        }
        for (int i = 0; i < 26; i++) names[i].clear();

        int n;
        cin >> n;
        for (int contestant = 0; contestant < n; contestant++){
            int k;
            cin >> k;
            res[contestant][t] = 1;
            for (int i = 0; i < k; i++){
                string word;
                cin >> word;
                char firstChar = tolower(word[0]);
                names[contestant][firstChar] = word;
                res[firstChar - 69][contestant] = 1;
            }
        }
        for (int i = 0; i < n; i++) res[s][i+28] = 1;

        mf = 0;
        while (true){
            f = 0;
            vector <int> dist(MAXV, INF);
            dist[s] = 0; queue<int> q; q.push(s);
            p.assign(MAXV,-1);
            while(!q.empty()){
                int u = q.front();q.pop();
                if (u == t) break;
                for (int v = 0; v < MAXV; v++)
                    if (res[u][v] > 0 && dist[v] == INF)
                        dist[v] = dist[u] + 1, q.push(v), p[v] = u;
            }
            augment(t,INF);
            if (f == 0) break;
            mf += f;
        }
        
        printf("Case #%d:\n", tcases-cases);
        for (int i =28; i <= 53; i++){
            for (int j = 0; j < 26; j++){
                if (res[j][i]) {
                    string name = names[j][i+69];
                    name[0] = toupper(name[0]);
                    int i = 1;
                    while(name[i]) {name[i] = tolower(name[i]); i++;}
                    cout << name << '\n';
                }
            }
        }
    }
}