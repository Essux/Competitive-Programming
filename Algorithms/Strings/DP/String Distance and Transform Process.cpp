#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 103
#define INF 1000000000

typedef pair<int, int> ii;
typedef pair<char, pair<int, int> > move_ii;

int dp[MAXN][MAXN];
char p[MAXN][MAXN];
vector<move_ii> steps;
string A, B;

int score(char a, char b) {
    if (a=='\0') return 1;
    else if (b=='\0') return 1;
    else if (a==b) return 0;
    else return 1;
}

void getSteps(int i, int j) {
    if (i < 0 || j < 0) return;
    char c = p[i][j];
    steps.push_back(move_ii(c, ii(i, j)));
    if (c == '-' || c == 's') getSteps(i-1, j-1);
    else if (c == 'd') getSteps(i-1, j);
    else if (c=='i') getSteps(i, j-1);
}

void needleman_wunsch() {
    for (int i = 0; i <= A.size(); i++) {
        for (int j = 0; j <= B.size(); j++) {
            if (i==0 || j==0) {
                dp[i][j] = i * score(A[i-1], '\0') + j * score('\0', B[j-1]);
                if (i==0 && j==0) p[i][j] = '-';
                else if (i==0) p[i][j] = 'i';
                else if (j==0) p[i][j] = 'd';
            }
            else {
                int option1 = dp[i-1][j-1] + score(A[i-1], B[j-1]);
                int option2 = dp[i-1][j] + score(A[i-1], '\0');
                int option3 = dp[i][j-1] + score('\0', B[j-1]);
                if (option1 <= option2) {
                    if (option1 <= option3) {
                        dp[i][j] = option1;
                        p[i][j] = (A[i-1]==B[j-1]) ? '-':'s';
                    }
                    else {
                        dp[i][j] = option3;
                        p[i][j] = 'i';
                    }
                }
                else {
                    if (option2 <= option3) {
                        dp[i][j] = option2;
                        p[i][j] = 'd';
                    }
                    else {
                        dp[i][j] = option3;
                        p[i][j] = 'i';
                    }
                }
            }
        }
    }
}

int main() {
    bool firstcase = true;
    while (getline(cin, A) && getline(cin, B)) {
        if (firstcase) firstcase = false;
        else printf("\n");
        if (B[B.size()-1] == '\r') A = A.substr(0, A.size()-1);
        //printf("%d\n", B[B.size()-1]);
        if (B[B.size()-1] == '\r') B = B.substr(0, B.size()-1);
        steps.clear();
        needleman_wunsch();
        //Print dp
        /*printf("    ");
        for (int i = 0; i < B.size(); i++) printf("%c ", B[i]);
        printf("\n");
        for (int i = 0; i <= A.size(); i++) {
            if (i==0) printf("  ");
            else printf("%c ", A[i-1]);
            for (int j = 0; j <= B.size(); j++) {
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }
        //Print parent
        printf("    ");
        for (int i = 0; i < B.size(); i++) printf("%c ", B[i]);
        printf("\n");
        for (int i = 0; i <= A.size(); i++) {
            if (i==0) printf("  ");
            else printf("%c ", A[i-1]);
            for (int j = 0; j <= B.size(); j++) {
                printf("%c ", p[i][j]);
            }
            printf("\n");
        }*/

        getSteps(A.size(), B.size());
        printf("%d\n", dp[A.size()][B.size()]);
        int bias = 0, moves = 1;
        for (int k = steps.size()-1; k >= 0; k--, moves++) {
            char move = steps[k].first;
            int i = steps[k].second.first;
            int j = steps[k].second.second;
            if (move == 'i') printf("%d Insert %d,%c\n", moves, i+(bias++)+1, B[j-1]);
            else if (move == 'd') printf("%d Delete %d\n", moves, i+(bias--), A[i-1]);
            else if (move == 's') printf("%d Replace %d,%c\n", moves, i+bias, B[j-1]);
            else moves--;
        }
    }
}