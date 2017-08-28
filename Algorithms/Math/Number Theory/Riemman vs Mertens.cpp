#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long ll;

#define MAXN 1000010

bitset<MAXN> bs;
ll mu[MAXN], M[MAXN];

void modifiedSieve() {
    bs.set();
    fill(mu, mu+MAXN, -2);
    mu[1] = 1;
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < MAXN; i++) {
        if (bs[i]) {
            for (ll j = 2 * i; j < MAXN; j += i) {
                if (i < 11000 and j % (i*i) == 0) mu[j] = 0;
                else if (mu[j] != 0) {
                    if (mu[j] == -2) mu[j] = 1;
                    else mu[j]++;
                }
                bs[j] = 0;
            }
        }
    }
}

int main() {
    int N;
    modifiedSieve();
    for (ll i = 2; i < MAXN; i++)
        if (mu[i] != 0) {
            if (mu[i] == -2) mu[i] = -1;
            else mu[i] = mu[i] % 2 == 0 ? 1 : -1;
        }

    M[1] = 1;
    for (ll i = 2; i < MAXN; i++)
        M[i] = mu[i] + M[i-1];
    while (scanf("%d", &N) and N) {
        printf("%8d%8d%8d\n", N, mu[N], M[N]);
    }
}