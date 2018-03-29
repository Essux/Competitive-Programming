#include <iostream>
#include <cstdio>

using namespace std;

#define K 35
#define D(_x) cout << #_x":" << _x << endl;

bool leftin[K];

int main() {
    int n; scanf("%d", &n);
    while (n--) {
        int a, p, q;
        fill(leftin, leftin+K, false);
        scanf("%d %d/%d", &a, &p, &q);
        int k = 0;
        while (p != 1 || q != 1) {
            if (p > q) p -= q;
            else q -= p, leftin[k] = true;
            k++;
        }
        int ans = 1 << k;
        for (int i = 0; i < k; i++) {
            if (!leftin[i]) ans += 1 << i;
        }
        printf("%d %d\n", a, ans);
    }
}