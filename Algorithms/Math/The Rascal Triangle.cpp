#include <cstdio>

using namespace std;

int main() {
    int P;
    scanf("%d", &P);
    while (P--) {
        int a, n, m;
        scanf("%d %d %d", &a, &n, &m);
        if (m==0 or m==n) {printf("%d 1\n", a); continue;}
        int delta = n-3;
        long long ans = n;
        if (m>n/2) m = n-m;
        for (int i = 1; i < m; i++){
            ans += delta;
            delta -= 2;
        }
        printf("%d %lld\n", a, ans);
    }
}