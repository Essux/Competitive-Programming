#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 2003
const long long MOD = 2147483647;

int n;
long long arr[MAXN];
long long memo[MAXN][MAXN];

long long dp(int i, int j) {
    if (j==n) return 1;
    if (memo[i][j] != -1) return memo[i][j];

    int maxA, maxI, minA, minI;
    if (arr[i] > arr[j]) maxA = arr[i], maxI = i, minA = arr[j], minI = j;
    else  maxA = arr[j], maxI = j, minA = arr[i], minI = i;

    if (minA < arr[j+1] && arr[j+1] < maxA) return memo[i][j] = (dp(minI, j+1) + dp(maxI, j+1))%MOD;
    if (minA < arr[j+1]) return memo[i][j] = dp(minI, j+1)%MOD;
    if (arr[j+1] < maxA) return memo[i][j] = dp(maxI, j+1)%MOD;
    return 0;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                memo[i][j] = -1;
        for (int i = 0; i <= n; i++) scanf("%lld", arr+i);
        printf("%lld\n", dp(0, 1));
    }
    return 0;
}