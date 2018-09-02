#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, ll> memo;

ll back(ll a) {
    if (memo.count(a)>0) return memo[a];
    return memo[a] = max(a, back(a/2)+back(a/3)+back(a/4));
}

int main() {
    ll n;
    while (cin >> n) {
        cout << back(n) << endl;
    }
}