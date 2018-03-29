#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll x, y; cin >> x >>y;
    ll a = max(x, y);
    ll b = min(x, y);
    bool win = true;
    while (a%b) {
        if (a/b > 1) break;
        win = !win;
        swap(a, b);
        b = b%a;
    }
    cout << (win ? "win" : "lose");
}