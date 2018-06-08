// Solution to Greedy Arkady - Codeforces R476 - C
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, k, M, D;
    cin >> n >> k >> M >> D;
    ll best = 0;
    ll d = min(D, (n+k-1)/k);
    while (d>0) {
        ll xmax = n/((d-1)*k+1);
        best = max(best, min(M, xmax)*d);
        d--;
    }
    cout << best << endl;
}