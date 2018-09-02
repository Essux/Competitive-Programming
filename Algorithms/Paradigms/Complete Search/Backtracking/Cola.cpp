// UVa 11150 - Cola
#include <bits/stdc++.h>

using namespace std;

const int INF = 1<<30;

int n;

int back(int a, int borr) {
    if (borr > a) return -INF;
    int ans = 0;
    for (int i = 0; i+borr <= a; i++) {
        int rem = (a+1)%3;
        int next = (a+1)/3 + rem;
        int news = (a+1)/3;
        int next_ans = news>0 ? back(next, borr + i) : 0;
        ans = max(ans, news +next_ans);
    }
    return ans;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", n+back(n, 0));
    }
}