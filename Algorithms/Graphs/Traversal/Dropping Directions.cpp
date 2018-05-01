//Droping Directions (Kattis)
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

struct inter {
    int a, b, c, d;
    inter() {a = b = c = d = 0;}
    inter(int _a,int _b,int _c,int _d) : a(_a), b(_b), c(_c), d(_d) {}
    bool first(int x) {
        return (x==b || x==d);
    }
    int next(int x) {
        if (x==a) return c;
        if (x==b) return d;
        if (x==c) return a;
        if (x==d) return b;
        return -1;
    }
};

inter arr[MAXN];
bool visited[MAXN][2];
int n, k;

bool dfs(int from, int in, bool ady) {
    visited[in][arr[in].first(from)] = true;
    //printf("From %d In %d\n", from+1, in+1);
    int next = arr[in].next(from);
    if (in==k) ady = true;
    if (!visited[next][arr[next].first(in)])
        return dfs(in, next, ady);
    return ady;
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        k--;
        for (int i = 0; i < n; i++) {
            int a, b, c, d; cin >> a >> b >> c >> d;
            arr[i] = inter(--a, --b, --c, --d);
        }
        for (int i = 0; i < n+1; i++)
            visited[i][0] = visited[i][1] = false;

        int cycles = 0, ady = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i][0]) ady += dfs(arr[i].a, i, false), cycles++;
            if (!visited[i][1]) ady += dfs(arr[i].b, i, false), cycles++;
        }
        //printf("Cycles %d Ady %d\n", cycles, ady);
        cout << (cycles-ady) << endl;
    }
}