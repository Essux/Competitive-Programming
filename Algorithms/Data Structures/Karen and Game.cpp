#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 103
#define INF 1<<30

int mat[MAXN][MAXN];

int main() {
    int R, C;
    scanf("%d %d", &R, &C);
    long long totalSum = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            scanf("%d", &mat[i][j]);
            totalSum += mat[i][j];
        }

    int moves = 0;
    long long partialSum = 0;

    if (R <= C) {
        int minR[R];
        fill(minR, minR + R, 0);
        for (int i = 0; i < R; i++) {
            int minA = INF;
            for (int j = 0; j < C; j++) {
                minA = min(minA, mat[i][j]);
            }
            if (minA < INF) {
                minR[i] = minA;
                partialSum += minA * C;
                moves += minA;
                for (int j = 0; j < C; j++) {
                    mat[i][j] -= minA;
                }
            }
        }

        if (partialSum == totalSum) {
            printf("%d\n", moves);
            for (int i = 0; i < R; i++)
                while(minR[i]--) printf("row %d\n", i+1);
        }
        else {
            int minC[C];
            fill(minC, minC + C, 0);
            for (int i = 0; i < C; i++) {
                int minA = INF;
                for (int j = 0; j < R; j++) minA = min(minA, mat[j][i]);
                if (minA < INF) {
                    minC[i] = minA;
                    partialSum += minA * R;
                    moves += minA;
                }
            }
            if (partialSum != totalSum) printf("-1");
            else {
                printf("%d\n", moves);
                for (int i = 0; i < R; i++)
                    while(minR[i]--) printf("row %d\n", i+1);
                for (int i = 0; i < C; i++)
                    while(minC[i]--) printf("col %d\n", i+1);
            }
        }
    }
    else {
        int minC[C];
        fill(minC, minC + C, 0);
        for (int i = 0; i < C; i++) {
            int minA = INF;
            for (int j = 0; j < R; j++) minA = min(minA, mat[j][i]);
            if (minA < INF) {
                minC[i] = minA;
                partialSum += minA * R;
                moves += minA;
                for (int j = 0; j < R; j++) mat[j][i] -= minA;
            }
        }

        if (partialSum == totalSum) {
            printf("%d\n", moves);
            for (int i = 0; i < C; i++)
                while(minC[i]--) printf("col %d\n", i+1);
        }
        else {
            int minR[R];
            fill(minR, minR + R, 0);
            for (int i = 0; i < R; i++) {
                int minA = INF;
                for (int j = 0; j < C; j++) {
                    minA = min(minA, mat[i][j]);
                }
                if (minA < INF) {
                    minR[i] = minA;
                    partialSum += minA * C;
                    moves += minA;
                    for (int j = 0; j < C; j++) {
                        mat[i][j] -= minA;
                    }
                }
            }
            if (partialSum != totalSum) printf("-1");
            else {
                printf("%d\n", moves);
                for (int i = 0; i < R; i++)
                    while(minR[i]--) printf("row %d\n", i+1);
                for (int i = 0; i < C; i++)
                    while(minC[i]--) printf("col %d\n", i+1);
            }
        }
    }
}