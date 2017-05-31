#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAXN 1000 + 5

typedef pair<int, int> IJ;
typedef pair<int, IJ> turnsIJ;
typedef pair<char, turnsIJ> dirturnsIJ;

char matrix[MAXN][MAXN];
int turns[MAXN][MAXN];

int main(){
    int R, C;
    scanf("%d %d", &R, &C);
    IJ start = IJ(-1, -1);
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> matrix[i][j];
            turns[i][j] = -1;
            if (matrix[i][j] == 'S') start = IJ(i, j);
        }
    }
    queue<dirturnsIJ> q;
    q.push(dirturnsIJ('0', turnsIJ(3, start)));
    bool found = false;
    while (!q.empty() and !found){
        dirturnsIJ curState = q.front(); q.pop();
        char curDir = curState.first;
        int curTurns = curState.second.first;
        int curI = curState.second.second.first;
        int curJ = curState.second.second.second;

        if (matrix[curI][curJ] == 'T') {found = true; break;}

        if (turns[curI][curJ] > curTurns) continue;
        matrix[curI][curJ] = '*';
        turns[curI][curJ] = curTurns;

        if (curI - 1 >= 0 and matrix[curI-1][curJ] != '*'){
            if (curDir == 'N') q.push(dirturnsIJ('N', turnsIJ(curTurns, IJ(curI-1, curJ))));
            else if (curTurns > 0) q.push(dirturnsIJ('N', turnsIJ(curTurns-1, IJ(curI-1, curJ))));
        }
        if (curI + 1 < R and matrix[curI+1][curJ] != '*'){
            if (curDir == 'S') q.push(dirturnsIJ('S', turnsIJ(curTurns, IJ(curI+1, curJ))));
            else if (curTurns > 0) q.push(dirturnsIJ('S', turnsIJ(curTurns-1, IJ(curI+1, curJ))));
        }
        if (curJ - 1 >= 0 and matrix[curI][curJ-1] != '*'){
            if (curDir == 'W') q.push(dirturnsIJ('W', turnsIJ(curTurns, IJ(curI, curJ-1))));
            else if (curTurns > 0) q.push(dirturnsIJ('W', turnsIJ(curTurns-1, IJ(curI, curJ-1))));
        }
        if (curJ + 1 < C and matrix[curI][curJ+1] != '*'){
            if (curDir == 'E') q.push(dirturnsIJ('E', turnsIJ(curTurns, IJ(curI, curJ+1))));
            else if (curTurns > 0) q.push(dirturnsIJ('E', turnsIJ(curTurns-1, IJ(curI, curJ+1))));
        }
    }

    /*for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            printf("%3d", turns[i][j]);
        }
        cout << endl;
    }
    cout << endl;*/

    cout << (found ? "YES":"NO");
}