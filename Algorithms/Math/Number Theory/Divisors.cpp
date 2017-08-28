#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;

#define MAXN 32000

bitset<MAXN> bs;
vector<ll> primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < MAXN; i++) {
        if (bs[i]) {
            for (ll j = i * i; j < MAXN; j += i) bs[i] = 0;
            primes.push_back(i);
        }
    }
}

ll numDiv(ll n) {
    int i = 0;
    ll PF = primes[i], ans = 1;
    while (PF * PF <= n) {
        ll power = 0;
        while (n % PF == 0) {n/=PF; power++;}
        ans *= power+1;
        PF = primes[++i];
    }
    if (n!=1) ans *= 2;
    return ans;
}

int main() {
    sieve();
    int N;
    scanf("%d", &N);
    while (N--) {
        ll L, U;
        scanf("%lld %lld", &L, &U);
        ll m = 1, n = 1;
        for (int i = L; i <= U; i++) {
            ll divs = numDiv(i);
            if (divs > m) {
                m = divs;
                n = i;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", L, U, n, m);
    }
}