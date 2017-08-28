#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000005

vector<int> primes;
bitset<MAXN> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i < MAXN; i++) if (bs[i]) {
        for (long long j = i*i; j < MAXN; j += i) bs[j] = 0;
        primes.push_back(i);
    }
}

int main() {
    int N;
    sieve();
    while (scanf("%d", &N) and N) {
        int i;
        bool found = false;
        for (i = 1; i < primes.size() and primes[i] < N; i++) {
            int cand = N - primes[i];
            if (bs[cand] and cand != 2) {
                found = true;
                break;
            }
        }
        if (found) printf("%d = %d + %d\n", N, primes[i], N - primes[i]);
        else printf("Goldbach's conjecture is wrong.\n");
    }
}