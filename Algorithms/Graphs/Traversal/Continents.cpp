#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 20 + 3

int m, n;
char grid[MAXN][MAXN];
char land;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int flood_fill(int x, int y){
    if (x < 0 or x >= n or y < 0 or y >= m) return 0;
    if (grid[x][y] != land) return 0;
    //printf("%d %d\n", x, y);
    grid[x][y] = 0;
    int size =1;
    for (int i = 0; i<4; i++) size += flood_fill(x+dx[i], y+dy[i]);
    if (x == n-1) size += flood_fill(0, y);
    if (x == 0) size += flood_fill(n-1, y);
    return size;
}


int main(){
    while (cin >> m >> n){
        for (int i = 0; i< m; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[j][i];

        int x, y;
        scanf("%d %d", &y, &x);
        land = grid[x][y];
        flood_fill(x, y);

        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j <n; j++)
                ans = max(ans, flood_fill(j, i));
                
        printf("%d\n", ans);
    }
}