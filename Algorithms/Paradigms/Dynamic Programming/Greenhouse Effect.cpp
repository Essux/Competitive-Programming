#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 5003

int n, m;
int LIS[MAXN], a[MAXN];

int dp(int index) {
    if (index == 0) return LIS[index] = 1;
    if (LIS[index] != -1) return LIS[index];
    int ans = 1;
    for (int i = 0; i < index; i++) {
        if (a[i] <= a[index]) ans = max(ans, dp(i)+1);
    }
    return LIS[index] = ans;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        float f;
        cin >> a[i] >> f;
    }
    fill(LIS, LIS+n+1, -1);
    for (int i = 0; i < n; i++) dp(i);
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(LIS[i], ans);
    printf("%d", n - ans);
}