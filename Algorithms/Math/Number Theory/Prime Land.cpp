#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <bitset>
#include <algorithm>

using namespace std;

#define MAXN 33000

bitset<MAXN> bs;
vector<int> primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        if (bs[i])
            for (int j = i * i; j < MAXN; j += i) {
                bs[j] = 0;
            }
        primes.push_back(i);
    }
}

bool isPrime(int n) {
    return bs[n];
}

vector<int> primeFactors(int n) {
    vector<int> factors;
    int i = 0, PF = primes[i];
    while (PF * PF <= n) {
        while (n % PF == 0) {
            factors.push_back(PF);
            n /= PF;
        }
        PF = primes[++i];
    }
    if (n!=1) factors.push_back(n);
    return factors;
}

int main() {
    int b, e;
    sieve();
    while (scanf("%d %d", &b, &e) and b != 0) {
        int N = pow(b, e);
        while (true) {
            if (cin.get() != ' ') break;
            scanf("%d %d", &b, &e);
            N *= pow(b, e);
        }
        vector<int> factors = primeFactors(--N);
        reverse(factors.begin(), factors.end());
        int curNum = factors[0], curTimes = 1;
        for (int i = 0; i < factors.size() - 1; i++) {
            if (curNum == factors[i+1]) {
                curTimes++;
            }
            else {
                printf("%d %d ", curNum, curTimes);
                curNum = factors[i+1];
                curTimes = 1;
            }
        }
        printf("%d %d\n", curNum, curTimes);
    }
}