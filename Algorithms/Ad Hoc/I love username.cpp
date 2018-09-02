// Solution to Codeforces Round 109 Div 2 - A
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int mx = -1, mn = 1<<30;
    int ans = -2;
    while (n--) {
        int a; cin >> a;
        if (a > mx) ans++;
        if (a < mn) ans++;
        mx = max(mx, a);
        mn = min(mn, a);
    }
    cout << ans << endl;
}