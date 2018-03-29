#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100;

int inc[MAXN][MAXN];
bool mat[MAXN][MAXN];

int main() {
    int t; cin >> t;
    while (t--) {
        int v, e; cin >> v >> e;
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < e; j++) {
                cin >> inc[i][j];
            }
        }
        bool ok = true;
        for (int i = 0; i < e && ok; i++) {
            int count = 0;
            for (int j = 0; j < v; j++) {
                count += inc[j][i];
            }
            if (count != 2) ok = false;
        }

        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                mat[i][j] = false;
            }
        }

        for (int i = 0; i < e && ok; i++) {
            int j, k;
            for (j = 0; j < v && !inc[j][i]; j++) {}
            for (k = j+1; k < v && !inc[k][i]; k++) {}
            if (!mat[j][k]) mat[j][k] = true;
            else ok = false;
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
}