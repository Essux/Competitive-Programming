// SPOJ Treats for the Cows - TRT
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000 + 5;

int n;
int arr[MAXN];
int memo[MAXN][MAXN];

int dp(int i, int j) {
    if (i>j) return 0;
    int &ans = memo[i][j];
    if (ans != -1) return ans;
    return ans = max(dp(i, j-1)+ arr[j]*(n-(j-i)), dp(i+1, j)+ arr[i]*(n-(j-i)));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    memset(memo, -1, sizeof(memo));
    cout << dp(0, n-1) << endl;
}