#include <cstdio>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

#define MAXN 2147483647
#define INF 1<<30
#define SIEVE_SIZE 50000

bitset<1000010> bs;
bitset<1000010> interval_bs;
int L, U;
vector<int> primes, interval_primes;
long long _sieve_size = 1000000;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i <= _sieve_size; i++) {
        if (bs[i]) {
            for (long long j = i * i; j <= _sieve_size; j += i) {
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

int isPrime(int n) {
    if (n <= _sieve_size) return bs[n];
    for (int i = 0; i < primes.size(); i++)
        if (n % primes[i] == 0) return false;
    return true;
}

int main() {
    sieve();
    while (scanf("%d %d", &L, &U) != EOF) {
        interval_primes.clear();
        interval_bs.set();
        for (int i = 0; i < primes.size(); i++) {
            int prime = primes[i];
            long long start = L % prime == 0 ? L : (long long) L + (prime - L % prime);
            if (start > U) continue;
            for (long long j = start; j <= (long long) U; j+=prime) {
                if (j!=prime) {
                    interval_bs[j-L] = 0;
                }
            }
        }

        if (L == 1) interval_bs[0] = 0;
        for (long long i = L; i <= U; i++)
            if (interval_bs[i-L]) interval_primes.push_back(i);

        if (interval_primes.size() < 2){
            printf("There are no adjacent primes.\n");
            continue;
        }
        pair<int, int> closest, farthest;
        int c = INF, f = -1;
        for (int i = 0; i < interval_primes.size()-1; i++) {
            int a = interval_primes[i], b = interval_primes[i+1];
            if (b-a < c) {
                c = b-a;
                closest = make_pair(a, b);
            }
            if (b-a > f) {
                f = b-a;
                farthest = make_pair(a, b);
            }
        }
        printf("%d,%d are closest, %d,%d are most distant.\n", closest.first, closest.second, farthest.first, farthest.second);
    }
}