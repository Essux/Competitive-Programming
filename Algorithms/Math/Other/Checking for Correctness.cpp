/*
* Solution to Checking for Correctness (Kattis)
* Logarithmic Exponentiation, Modular Arithmetic
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e4;

ll fast_exp(ll b, ll e) {
    ll ans = 1;
    b %= MOD;
    while (e) {
        if (e & 1) ans = (ans * b)%MOD;
        b = (b*b)%MOD;
        e >>= 1;
    }
    return (ans%MOD);
}

int main() {
    ll a, b; char c;
    while (cin >> a >> c >> b) {
        if (c=='+') {
            cout << (((a%MOD) + (b%MOD))%MOD) << endl;
        }
        else if (c=='*') {
            cout << (((a%MOD) * (b%MOD))%MOD) << endl;
        }
        else {
            cout << (fast_exp(a, b)) << endl;
        }
    }
}