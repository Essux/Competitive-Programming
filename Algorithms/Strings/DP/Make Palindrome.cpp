#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

#define MAXN 1005

string S;
int memo[MAXN][MAXN];

string getAnswer(int l, int r) {
    if (l==r) {string ans (1, S[l]); return ans;}
    if (l+1==r) {
        if (S[l]==S[r]) {string ans (1, S[l]); return ans+S[r];}
        string ans(1, S[r]); return (ans+S[l])+S[r];
    }
    if (S[l]==S[r]) return S[l]+getAnswer(l+1, r-1)+S[r];
    if (memo[l][r]==memo[l+1][r]+1) return S[l]+getAnswer(l+1, r)+S[l];
    return S[r]+getAnswer(l, r-1)+S[r];
}

int dp(int l, int r) {
    int &ans = memo[l][r];
    if (ans!=-1) return ans;
    if (l==r) return ans = 0;
    if (l+1==r) {
        if (S[l]==S[r]) return ans =  0;
        return ans = 1;
    }
    if (S[l]==S[r]) return ans = dp(l+1, r-1);
    return ans = 1+min(dp(l+1, r), dp(l, r-1));
}

int main() {
    while (getline(cin, S)) {
        if (S[S.size()-1]=='\r') S = S.substr(0, S.size()-1);
        if (S.size()==0) {printf("0 \n"); continue;}
        for (int i= 0; i < S.size(); i++)
            for (int j = 0; j < S.size(); j++)
                memo[i][j] = -1;
        printf("%d ", dp(0, S.size()-1));
        cout << getAnswer(0, S.size()-1) << '\n';
    }
}