#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 104;

#define D(_x) cout << #_x":" << _x << endl;

char s[MAXN];
int sz;
bool memo[MAXN][MAXN][3];
bool visited[MAXN][MAXN][3];
int trans[3][3] = {
    {1, 0, 2},
    {0, 1, 1},
    {2, 1, 0}
};

void dp() {
    for (int i = 0; i < sz; i++) {
        for (int j = 0; i+j < sz; j++) {
            if (i==0) memo[j][j][s[j]-'X'] = 1;
            for (int k = j; k < i+j; k++) {
                for (int p = 0; p < 3; p++) {
                    if (memo[j][k][p])
                    for (int q = 0; q < 3; q++) {
                        if (memo[k+1][j+i][q]) {
                            //printf("(%d %d %c) ^ (%d %d %c) -> (%d %d %c)\n", j, k, p+'X', k+1, j+i, q+'X', j, j+i, trans[p][q]+'X');
                            memo[j][j+i][trans[p][q]] = 1;
                        }
                    }
                }
                if(memo[j][j+i][0] && memo[j][j+i][1] && memo[j][j+i][2]) break;
            }
        }
    }
}



int main() {
    int n; scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        sz = strlen(s);
        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++) {
                memo[i][j][0] = memo[i][j][1] = memo[i][j][2]  = false;
                visited[i][j][0] = visited[i][j][1] = visited[i][j][2]  = false;
            }
        }
        dp();
        if (memo[0][sz-1][2]) printf("Z\n");
        else if (memo[0][sz-1][1]) printf("Y\n");
        else if (memo[0][sz-1][0]) printf("X\n");
    }
}