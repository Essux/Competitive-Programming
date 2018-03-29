#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define MAXN 103
#define INF 1000000000

int dp[MAXN][MAXN];
string A, B;

int score(char a, char b) {
    if (a=='\0') return 0;
    else if (b=='\0') return 0;
    else if (a==b) return 1;
    else return -INF;
}

void needleman_wunsch() {
    for (int i = 0; i <= A.size(); i++) {
        for (int j = 0; j <= B.size(); j++) {
            if (i==0 || j==0) dp[i][j] = i * score(A[i-1], '\0') + j * score('\0', B[j-1]);
            else {
                int option1 = dp[i-1][j-1] + score(A[i-1], B[j-1]);
                int option2 = dp[i-1][j] + score(A[i-1], '\0');
                int option3 = dp[i][j-1] + score('\0', B[j-1]);
                dp[i][j] = max(max(option1, option2), option3);
            }
        }
    }
}

int main() {
    int ncase = 1;
    while (getline(cin, A) && A[0] != '#') {
        getline(cin, B);
        if (A[A.size()-1] == '\r') A = A.substr(0, A.size()-1);
        if (B[B.size()-1] == '\r') B = B.substr(0, B.size()-1);
        needleman_wunsch();
        printf("Case #%d: you can visit at most %d cities.\n", ncase++, dp[A.size()][B.size()]);
    }
}