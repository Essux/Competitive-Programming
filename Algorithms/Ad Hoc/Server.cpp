#include <cstdio>

using namespace std;

#define MAXN 51

int nums[MAXN];

int main() {
    int n, T;
    while (scanf("%d %d", &n, &T) != EOF) {
        for (int i =0; i<n; i++) scanf("%d", nums+i);
        int i = 0, sum = 0;
        while (i < n && (sum + nums[i]) <= T) {
            sum += nums[i++];
        }
        printf("%d\n", i);
    }
}