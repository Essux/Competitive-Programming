// Codeforces Round #309 (Div. 2) - B
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    map<string, int> m;
    int ans = 0;
    while (n--) {
        string a; cin >> a;
        m[a]++;
        ans = max(ans, m[a]);
    }
    cout << ans << endl;
}