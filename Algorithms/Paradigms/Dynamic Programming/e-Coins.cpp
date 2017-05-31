#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define INF 1<<30
#define MAXM 43
#define MAX_XY 300 + 5

int N, S, M;
int coins[MAXM][2];
int memo[MAX_XY][MAX_XY];

int cc(int x, int y){
    if (x*x + y*y >  S*S) { return INF;}
    if (x*x + y*y == S*S) { return 0;}
    if (memo[x][y] != -1) {return memo[x][y];}
    int m = INF;
    for (int i = 0; i < M; i++){
        int a =  1 + cc(x+coins[i][0], y+coins[i][1]);
        m = min(m , a);
    }
    return memo[x][y] = m;
}

int main(){
    cin >> N;
    while (N--){
        for (int i = 0; i < MAX_XY; i++){
            for (int j = 0; j < MAX_XY; j++){
                memo[i][j] = -1;
            }
        }
        cin >> M >> S;
        for (int i = 0; i < M; i++){
            cin >> coins[i][0] >> coins[i][1];
        }
        int ans = cc(0, 0);
        if (ans >= INF) printf("not possible\n");
        else printf("%d\n", ans);
    }
}