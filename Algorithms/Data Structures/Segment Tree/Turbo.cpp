// Kattis - Turbo
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 +5;

int n;
int arr[MAXN], pos[MAXN], stq[MAXN];
int t[2*MAXN];

void reset() {
    for (int i = 0; i<2*n; i++) t[i] = 0;
}

int modify(int pos, int val) {
    for (t[pos+=n] = val; pos > 1; pos >>=1) t[pos>>1] = t[pos] + t[pos^1];
}

int query(int l, int r) {
    int ans = 0;
    for (l += n, r += n+1; l < r; l>>=1, r>>=1) {
        if (l&1) ans += t[l++];
        if (r&1) ans += t[--r];
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[--arr[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        int a = arr[i];
        if (a<n/2) stq[a] = query(a+1, n-1-a);
        modify(a, 1);
    }

    reset();
    for (int i = n-1; i >= 0; i--) {
        int a = arr[i];
        if (a>n/2) stq[a] = query(n-a, a-1);
        modify(a, 1);
    }

    int l = 0, r = n-1;
    int it = 0;
    while (l<=r) {
        if (it==0) printf("%d\n", stq[l++]);
        else printf("%d\n", stq[r--]);
        it = 1 - it;
    }
}