// Kattis, Kattis - Workout for a Dumbbell
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10 + 2;

int mu[MAXN], mr[MAXN];
int uu[MAXN], rr[MAXN], tt[MAXN];

int nextAvalTime(int afterT, int i) {
    if (afterT < tt[i]) return afterT;
    int p = uu[i] + rr[i];
    return max((afterT-tt[i])%p, uu[i]) + ((afterT-tt[i])/p)*p + tt[i];
}

int nextPeriod(int t, int i) {
    if (t < tt[i]) return tt[i];
    int p = uu[i] + rr[i];
    return t + rr[i] - (((t-tt[i])%p) - uu[i]);
}

int main() {
    for (int i = 0; i < 10; i++)
        cin >> mu[i] >> mr[i];

    for (int i = 0; i < 10; i++)
        cin >> uu[i] >> rr[i] >> tt[i];

    int t = 0;
    for (int it = 0; it < 3; it++) {
        for (int i = 0; i < 10; i++) {
            t = nextAvalTime(t, i);
            tt[i] = max(nextPeriod(t, i), t + mu[i]);
            t += mu[i] + mr[i];
        }
    }
    printf("%d\n", t-mr[9]);
}