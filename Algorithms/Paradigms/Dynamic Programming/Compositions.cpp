#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAXN 33
#define INF 1<<30
#define D(_x) cout << #_x":" << _x << endl;

bool available[MAXN];
int memo[MAXN];

int dp(int n) {
    if (n==0) return 1;
    if (n<0) return 0;
    int &sols = memo[n];
    if (sols!=-1) return sols;
    sols = 0;
    for (int i = 1; i <= n; i++)
        if (available[i]) sols += dp(n-i);
    return sols;
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int a, n, m, k;
        scanf("%d %d %d %d", &a, &n, &m, &k);
        fill(available, available+MAXN, true);
        int i = m;
        while (i <= 30)
            available[i] = false,
            i += k;
        fill(memo, memo+MAXN, -1);
        printf("%d %d\n", a, dp(n));
    }
}