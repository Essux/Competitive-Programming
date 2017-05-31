#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000 + 5
#define INF 1 << 30

int w[MAXN][10+3];
int memo[MAXN][10+3];
int X;

int dp(int alt, int x){
    if (x == X-1) {
        if (alt == 9) {
            return -w[x][alt] + 30;
        }
        return -w[x][alt] + 20;
    }
    if (memo[x][alt] != -1) return memo[x][alt];
    
    int cand = INF;
    if (9 - (alt-1) <= (X-1) - (x+1) + 1 and alt - 1 >= 0) {
        cand = min(cand, dp(alt - 1, x + 1) + 60);
    }
    if (9 - (alt) <= (X-1) - (x+1) + 1){
        cand = min(cand, dp(alt, x + 1) + 30);
    }
    if (alt + 1 <= 9) {
        cand = min(cand, dp(alt + 1, x + 1) + 20);
    }
    return memo[x][alt] = cand - w[x][alt]; 
}


int main(){
    int T; cin >> T;
    while (T--){
        cin >> X;
        X /= 100;
        for (int j = 0; j< 10; j++){
            for (int i = 0; i < X; i++){
                scanf("%d", &w[i][j]);
            }
        }
        for (int i = 0; i < X; i++){
            for (int j = 0; j < 10; j++){
                memo[i][j] = -1;
            }
        }
        printf("%d\n\n", dp(9, 0));
    }
}