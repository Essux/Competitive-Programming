#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    for (int ncase = 1; ncase <= N; ncase++) {
        double d, v, u;
        cin >> d >> v >> u;
        if (u <= v or u == 0 or v==0) {
            printf("Case %d: can't determine\n", ncase);
            continue;
        }
        double r  = sqrt(u*u - v*v);
        printf("Case %d: %.3f\n", ncase, abs(d/u - d/r));
    }
}