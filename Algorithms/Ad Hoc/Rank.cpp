// Codeforces Round 502 A - The Rank
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int w, x, y, z;
    cin >> w >> x >> y >> z;
    int sum = w + x + y + z;
    int ans = 0;
    while (--n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int s = a + b + c + d;
        if (s>sum) ans++;
    }
    cout << ans+1<< endl;
}