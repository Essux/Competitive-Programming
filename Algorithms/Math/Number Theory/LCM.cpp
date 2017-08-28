#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAXN 1000010

typedef pair<int, int> ii;

bitset<MAXN> bs;
vector<int> primes;
int decomposition[MAXN], numAns[MAXN];

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (long long i = 2; i < MAXN; i++) {
        if (bs[i]) {
            for (long long  j = i*i; j < MAXN; j += i) bs[j] = 0;
            primes.push_back(i);
        }
    }
}

vector<ii> primeFactors(int n) {
    vector<ii> factors;
    int i = 0, PF = primes[i];
    while (PF * PF <= n) {
        int count = 0;
        while (n % PF == 0) {n /= PF; count++;}
        if (count > 0) {
            factors.push_back(make_pair(PF, count));
        }
        PF = primes[++i];
    }
    if (n != 1) factors.push_back(make_pair(n, 1));
    return factors;
}

int main() {
    int N;
    sieve();
    fill(decomposition, decomposition + MAXN -1, 0);
    long long cur = 1;
    numAns[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        vector<ii> factors = primeFactors(i);
        for (int j = 0; j < factors.size(); j++) {
            int a = factors[j].first, times = factors[j].second;
            if (times > decomposition[a]) {
                cur *= (long long) pow(a, times - decomposition[a]);
                decomposition[a] = times;
            }
            while (cur % 10 == 0) cur /= 10;
            cur %= 1000000;
        }
        numAns[i] = cur % 1000000;
    }


    while (scanf("%d", &N) and N) {
        printf("%d\n", numAns[N] % 10);
    }
}