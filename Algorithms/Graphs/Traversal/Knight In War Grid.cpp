#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

#define MAXN 100 + 4
#define WATER 0
#define VISITED 1
#define UNVISITED 2

typedef pair<int, int> xy;

int grid[MAXN][MAXN];
int R, C, m, n;
int even, odd;

void dfs(int x, int y){
    //printf("In %d %d\n", x, y);
    grid[x][y] = VISITED;
    int possib = 0;
    set<xy> fol;
    for (int s1 = -1; s1<=1; s1 += 2){
        for (int s2 = -1; s2<=1; s2 += 2){
            if (x + m*s1 >= 0 and x + m*s1 < C)
                if (y + n*s2 >= 0 and y + n*s2 < R)
                    if (grid[x + m*s1][y + n*s2] != WATER) {
                        //printf("From %d %d to %d %d\n", x, y, x + m*s1, y + n*s2);
                        possib++;
                        fol.insert(xy(x + m*s1, y + n*s2));
                        if (grid[x + m*s1][y + n*s2] != VISITED) dfs(x + m*s1, y + n*s2);
                    }

            if (y + m*s1 >= 0 and y + m*s1 < R)
                if (x +n*s2 >= 0 and x + n*s2 < C)
                    if (grid[x + n*s2][y + m*s1] != WATER) {
                        //printf("From %d %d to %d %d\n", x, y, x + n*s2, y + m*s1);
                        possib++;
                        fol.insert(xy(x + n*s2, y + m*s1));                        
                        if (grid[x + n*s2][y + m*s1] != VISITED) dfs(x + n*s2, y + m*s1);
                    }
        }
    }

    if (fol.size() % 2 == 0) even++;
    else odd++;
}

int main(){
    int T; cin >> T;
    for (int ncase = 1; ncase <=  T; ncase++){
        cin >> R >> C >> m >> n;
        int w;
        cin >> w;
        for (int i = 0; i < C; i++)
            for (int  j =0; j < R; j++)
                grid[i][j] = UNVISITED;

        while (w--){
            int x, y;
            cin >> x >> y;
            grid[y][x] = WATER;
        }
        even = 0;
        odd = 0;
        dfs(0, 0);

        /*for (int i = 0; i< R; i++){
            for (int j = 0; j < C; j++)
                cout << grid[j][i] << " ";
            cout << endl;
        }*/

        printf("Case %d: %d %d\n", ncase, even, odd);
    }
}