// Solution to UVa - 13071 Double decker
#include <cstdio>

using namespace std;

int main() {
    int a; scanf("%d", &a);
    while (a--) {
        int n, m; scanf("%d %d", &n, &m);
        int s = n+m;
        printf("%d\n", (s*(s+1)/2) + 1 + n);
    }
}