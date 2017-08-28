#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

#define D(_x) //cout << #_x":" << _x << endl;

int main() {
    int N, M;
    scanf("%d %d\n", &N, &M);
    char matrix[N][M];
    bool belong[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%c", &matrix[i][j]);
            belong[i][j] = true;
        }
        scanf("\n");
    }
    int lets[28];
    for (int i = 0; i < N; i++) {
        fill(lets, lets + 28, 0);
        for (int j = 0; j < M; j++) {
            lets[matrix[i][j] - 'a']++;
        }
        for (int j = 0; j < M; j++)
            if (lets[matrix[i][j] - 'a'] >= 2) {
                D(matrix[i][j]);
                belong[i][j] = false;
            }
    }
    for (int i = 0; i < M; i++) {
        fill(lets, lets + 28, 0);
        for (int j = 0; j < N; j++) {
            lets[matrix[j][i] - 'a']++;
        }
        for (int j = 0; j < N; j++)
            if (lets[matrix[j][i] - 'a'] >= 2) {
                belong[j][i] = false;
                D(matrix[j][i]);
            }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (belong[i][j]) printf("%c", matrix[i][j]);
        }
    }
}