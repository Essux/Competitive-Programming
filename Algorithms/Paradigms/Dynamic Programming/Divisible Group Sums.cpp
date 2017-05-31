#include <cstdio>

using namespace std;

#define MAXN 200 + 4
#define MAXD 20 + 2
#define MAXM 10 + 2

int N, Q, D, M;
int x[MAXN];
long long memo[50][MAXN][MAXM]; //D-i-m

long long value(int _D, int i, int m){
    if (m == 0)
        if (_D == 0) return 1;
        else return 0;
    if (i>=N) return 0;
    if (memo[_D + MAXD][i][m] != -1) {return memo[_D + MAXD][i][m];}
    return memo[_D + MAXD][i][m] = value((_D+x[i])%D, i+1, m-1) + value(_D, i+1, m);
}

int main(){
    int TC = 0;
    while (scanf("%d %d", &N, &Q) != EOF and N){
        for (int i = 0; i < N; i++) scanf("%d", x+i);
        printf("SET %d:\n", ++TC);
        for (int nq = 0; nq < Q; nq++){
            scanf("%d %d", &D, &M);

            for (int i = 0; i < 50; i++)
                for (int j = 0; j < MAXN; j++)
                    for (int k = 0; k < MAXM; k++)
                        memo[i][j][k] = -1;
            
            printf("QUERY %d: %ld\n", nq+1, value(0, 0, M));
        }
    }
}