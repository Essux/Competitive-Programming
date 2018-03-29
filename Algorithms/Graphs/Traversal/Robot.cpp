#include <bits/stdc++.h>

using namespace std;

#define MAXN 53
#define INF 1<<30

typedef pair<int, int> ii;
typedef pair<ii, int> iidir;

int obstacles[MAXN][MAXN], obs2[MAXN][MAXN];
int mat[4][MAXN][MAXN]; //M, N
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int M, N;

int bfs(int c, int r, int dir) {
    queue<iidir> q;
    q.push(iidir( ii(r, c), dir ));
    mat[dir][r][c] = 0;

    while (!q.empty()) {
        int curR = q.front().first.first;
        int curC = q.front().first.second;
        int dir = q.front().second;
        //printf("At r:%d c:%d dir:%d\n", curR, curC, dir);
        q.pop();

        //Move
        for (int i = 1; i <= 3; i++) {
            int nextC = curC + dx[dir]*i;
            int nextR = curR + dy[dir]*i;
            if (nextC >= 0 and nextC < N and nextR >= 0 and nextR < M) {
                if (obs2[nextR][nextC]) break;
                if (mat[dir][nextR][nextC] > mat[dir][curR][curC]+1) {
                    mat[dir][nextR][nextC] = mat[dir][curR][curC]+1;
                    q.push(iidir( ii(nextR, nextC) , dir));
                }
            }
        }

        //Rotate
        int der = (dir + 1) % 4;
        if (mat[der][curR][curC] > mat[dir][curR][curC]+1 and !obs2[curR][curC]) {
            mat[der][curR][curC] = mat[dir][curR][curC]+1;
            q.push(iidir( ii(curR, curC) , der));
        }
        int izq = (dir + 4 - 1) % 4;
        if (mat[izq][curR][curC] > mat[dir][curR][curC]+1 and !obs2[curR][curC]) {
            mat[izq][curR][curC] = mat[dir][curR][curC]+1;
            q.push(iidir( ii(curR, curC) , izq));
        }
    }

}

int main() {
    while (scanf("%d %d", &M, &N) and M and N) {
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &obstacles[i][j]);

            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    obs2[i][j] = 0;

            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    if (obstacles[i][j] == 1) {
                        obs2[i+1][j] = 1;
                        obs2[i][j+1] = 1;
                        obs2[i+1][j+1] = 1;
                        obs2[i][j] = 1;
                    }



        for (int i = 0; i < 4; i++)
            for (int j = 0; j <= M; j++)
                for (int k = 0; k <= N; k++)
                    mat[i][j][k] = INF;

        int fromR, fromC, toR, toC;
        scanf("%d %d %d %d", &fromR, &fromC, &toR, &toC);
        string direction;
        cin >> direction;
        int dir;
        switch(direction[0]) {
            case 'n':   dir = 1;
                        break;
            case 'e':   dir = 2;
                        break;
            case 's':   dir = 3;
                        break;
            case 'w':   dir = 0;
                        break;
        }

        for (int i = 0; i <= M; i++) obs2[i][0] = 1;
        for (int i = 0; i <= N; i++) obs2[0][i] = 1;

        /*for (int i = 0; i <= M; i++) {
            for (int j = 0; j <= N; j++) {
                if (fromC == j and fromR == i) printf("f ");
                else if (toC == j and toR == i) printf("t ");
                else printf("%d ", obs2[i][j]);
            }
            printf("\n");
        }*/

        bfs(fromC, fromR, dir);

        /*for (int i = 0; i <= M; i++) {
            for (int j = 0; j <= N; j++) {
                int minA = 1<<30;
                for (int k = 0; k < 4; k++){
                    minA = min(minA, mat[k][i][j]);
                }
                if (minA == 1<<30) printf("  in");
                else printf("%3d ", minA);
            }
            printf("\n");
        }*/

        int minA = 1<<30;
        for (int i = 0; i < 4; i++){
            minA = min(minA, mat[i][toR][toC]);
        }
        if (minA == INF or obs2[fromR][fromC]==1) printf("-1\n");
        else printf("%d\n", minA);
    }
}
