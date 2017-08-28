#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

#define MAXN 105

int a[MAXN], b[MAXN];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", a + i);
    for (int i = 0; i < K; i++) scanf("%d", b + i);
    sort(b, b + K, greater<int>());
    int j = 0;
    for (int i = 0; i < N; i++)
        if (a[i] == 0) a[i] =b[j++];
    for (int i = 0; i < N - 1; i++)
        if (a[i+1] <= a[i]) {
            printf("Yes");
            return 0;
        }
    printf("No");
}