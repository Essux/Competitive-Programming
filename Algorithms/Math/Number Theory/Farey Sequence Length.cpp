#include <bitset>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

#define MAXN 103

bitset<105> bs;
int coprime[MAXN * MAXN];
vector<int> primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i <= MAXN; i++) if (bs[i]) {
        int count = 1;
        for (int j = i * i; j <= MAXN * MAXN; j += i) bs[j] = 0;
        primes.push_back(i);
    }
}

ll eulerPhi(ll N) {
    int i = 0, PF = primes[i], ans = N;
    while(PF * PF <= N) {
        if (N % PF == 0) ans -= ans / PF;
        while (N % PF == 0) N /= PF;
        PF = primes[++i];
    }
    if (N != 1) ans -= ans /N;
    return ans;
}

int main() {
    sieve();
    coprime[1] = 2;
    for (int i = 2; i < MAXN * MAXN; i++) {
        coprime[i] = coprime[i-1] + eulerPhi(i);
    }
    int P;
    scanf("%d", &P);
    while (P--) {
        int a, n;
        scanf("%d %d", &a, &n);
        printf("%d %lld\n", a, coprime[n]);
    }
}