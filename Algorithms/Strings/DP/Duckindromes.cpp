// UVa 13072 - Duckindromes
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 3;

int memo[MAXN][MAXN];
string s;
char out[MAXN];

int dp(int i, int j) {
    if (i>j) return 0;
    if (i==j) return 1;
    int &ans = memo[i][j];
    if (ans!=-1) return ans;
    ans = 0;
    if (s[i]==s[j]) ans = max(2+dp(i+1, j-1), ans);
    ans = max(dp(i+1, j), ans);
    return ans = max(ans, dp(i, j-1));
}

void getAnswer(int i, int j, int a, int b) {
    if (i>j) return;
    if (i==j) {out[a] = s[i]; return;}
    if (dp(i, j)==dp(i+1,j)) return getAnswer(i+1, j, a, b);
    if (s[i]==s[j] && dp(i, j)==2+dp(i+1,j-1)) {
        out[a++] = s[i];
        out[b--] = s[j];
        return getAnswer(i+1, j-1, a, b);
    }
    if (dp(i, j)==dp(i, j-1)) return getAnswer(i, j-1, a, b);
}

int main() {
    while (cin >> s) {
        memset(memo, -1, sizeof(memo));
        int m = dp(0, s.size()-1);
        getAnswer(0, s.size()-1, 0, m-1);
        for (int i = 0; i<m; i++) printf("%c", out[i]);
        printf("\n");
    }
}