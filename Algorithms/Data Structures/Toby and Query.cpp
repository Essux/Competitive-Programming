// Solution to UVa - 13095 Tobby and Query
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10e5 + 5;

int addTable[10][MAXN];
int arr[MAXN];

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) scanf("%d", arr+i);
        for (int i = 0; i < 10; i++) {
            int acum = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j]==i) acum++;
                addTable[i][j] = acum;
            }
        }
        int q;
        scanf("%d", &q);
        while (q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            l--; r--;
            int ans = 0;
            for (int i = 0; i < 10; i++) {
                int lsum = (r==0)? 0 : addTable[i][l-1];
                int rsum = addTable[i][r];
                if (rsum - lsum > 0) ans++;
            }
            cout << ans << '\n';
        }
    }
}