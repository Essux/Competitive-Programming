#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 35
#define MAXW 1002
#define D(_x) cout << #_x":" << _x << endl;

int V[MAXN], W[MAXN]; //Value and weight
int N, memo[MAXN][MAXW];
vector<int> ans;

int dp(int id, int resW) {
    if (id>=N or resW==0) return memo[id][resW] = 0;
    if (memo[id][resW]!=-1) return memo[id][resW];
    if (W[id]>resW) return memo[id][resW] = dp(id+1, resW);
    return memo[id][resW] = max(
        dp(id+1, resW),
        V[id] + dp(id+1, resW-W[id]));
}

void print_ans(int id, int resW) {
    if (id>=N or resW==0) return;
    if (dp(id+1, resW) == memo[id][resW])
        print_ans(id+1, resW);
    else {
        ans.push_back(id);
        print_ans(id+1, resW-W[id]);
    }
}

int main() {
    int t, w, caseN=0;
    while (cin >> t >> w) {
        if (caseN==0) caseN++;
        else printf("\n");
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            int d, v;
            scanf("%d %d", &d, &v);
            V[i] = v;
            W[i] = 3*w*d;
        }
        for (int i = 0; i < MAXN; i++) fill(memo[i], memo[i]+MAXW, -1);
        printf("%d\n", dp(0, t));
        ans.clear(); print_ans(0, t);
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++) {
            int a = ans[i];
            printf("%d %d\n", W[a]/3/w, V[a]);
        }
    }
}