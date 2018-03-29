#include <cstdio>

using namespace std;

int main() {
    int P;
    scanf("%d", &P);
    while (P--) {
        int a, n;
        scanf("%d %d", &a, &n);
        printf("%d %d %d %d\n", a, (n * (n+1))/2, n*(n+1) - n, n*(n+1));
    }
}