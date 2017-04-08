#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

#define MAXN 1000 + 3

int graph[MAXN][MAXN];
int color[MAXN];
int team[MAXN];

bool colorTraverse(int n){
    int nextColor = 1;
    fill(color, color+MAXN, 0);
    fill(team, team+MAXN, 0);
    for (int i = 0; i < n; i++){
        if (color[i] == 0) {
            color[i] = nextColor++;
            team[color[i]-1]++;

            int curColor = color[i];
            for (int j = 0; j < n; j++){
                int nextColor = color[j];
                if (graph[i][j]){
                    if (nextColor == 0) {
                        color[j] = curColor;
                        team[color[i]-1]++;
                    }
                    else if (nextColor != curColor) return false;
                }
            }
        }
        else {
            int curColor = color[i];
            for (int j = 0; j < n; j++){
                if (graph[i][j] xor curColor==color[j]) return false;
            }
        }
    }
    return true;
}

int main(){
    int n;
    scanf("%d", &n);
    char curChar;
    for (int i = 0; i < n; i++){
        string line;
        cin >> line;
        for (int j = 0; j < n; j++){
            if (line[j]=='S') graph[i][j] = 1;
            else graph[i][j] = 0;
        }
    }
    if (!colorTraverse(n)) printf("-1");
    else {
        int i = 0;
        for (; i < MAXN && team[i] > 0; i++){}
        printf("%d\n", i);
        sort(team, team+i, greater<int>());
        for (int j = 0; j < i; j++){
            if (j) cout << " ";
            cout << team[j];
        }
    }
}