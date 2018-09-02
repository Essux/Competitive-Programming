//SPOJ 	Prime Path - PPATH
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e4 + 5;
const int INF = 1<<30;

bitset<MAXN + 5> bs;
vector<int> primes;
vector<int> g[MAXN];
int d[MAXN];

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < MAXN; i++)
        if (bs[i]) {
            for (ll j = i*i; j < MAXN; j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

int pow(int b, int e) {
    int ans = 1;
    for (int i = 0; i < e; i++) ans *= b;
    return ans;
}

void generateAdjacent(int a, int pot) {
    if (pot<0) return;
    int from = pot==3 ? 1 : 0;
    for (int i = from; i < 10; i++) {
        int cur_dig = (a / pow(10, pot))%10;
        int next = a + (i - cur_dig) * pow(10, pot);
        g[a].push_back(next);
    }
    generateAdjacent(a, pot-1);
}

void bfs(int a) {
    for (int i = 0; i < g[a].size(); i++) {
        int v = g[a][i];
        if (d[a]+1 < d[v]) d[v] = d[a]+1, bfs(v);
    }
}

int main() {
    sieve();
    for (int i = 0; i < primes.size(); i++) {
        if (primes[i]>999) generateAdjacent(primes[i], 3);
    }
    int n; cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        fill(d, d+MAXN, INF);
        d[a] = 0;
        bfs(a);
        if (d[b]>=INF) cout << "Impossible\n";
        else cout << d[b] << endl;
    }
}
