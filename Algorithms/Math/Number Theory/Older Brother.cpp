#include <bits/stdc++.h>

using namespace std;

#define D(_x) cout << #_x":" << _x << endl;

typedef long long ll;

const ll MAXN = 32000;

bitset<MAXN> bs;
vector<ll> primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < MAXN; i++) {
        if (bs[i]) {
            for (ll j = i*i; j < MAXN; j+=i) bs[j] = 0;
            primes.push_back(i);
        }
    }
}

bool isPower(ll a) {
    if (a==1) return false;
    for (int i = 0; i < primes.size(); i++) {
        ll p = primes[i];
        if (a%p==0) {
            while (a%p==0) a /= p;
            return a == 1LL;
        }
    }
    return true;
}

int main() {
    ll n; cin >> n;
    sieve();
    cout << (isPower(n) ? "yes" : "no");
}