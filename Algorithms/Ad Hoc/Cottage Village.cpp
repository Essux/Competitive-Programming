// Codeforces Beta Round 15 - Cottage Village
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t; cin >> n >> t;
    n *= 2; t *= 2;
    vector<int> v;
    for (int i = 0; i < n/2; i++) {
        int x, a; cin >> x >> a;
        x *= 2; a *= 2;
        v.push_back(x-a/2);
        v.push_back(x+a/2);
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 1; i+1 < n; i+=2) {
        int diff = v[i+1] - v[i];
        if (diff > t) ans += 2;
        else if (diff == t) ans++;
    }
    printf("%d\n", ans+2);
}