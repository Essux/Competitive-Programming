// Enlarge GCD - Codeforces Round #511 (Div. 2) C
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXA = 5000;
const int MAXN = 4e5;

bitset<MAXA + 5> bs;
vector<int> primes;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < MAXA; i++)
        if (bs[i]) {
            for (ll j = i*i; j < MAXA; j += i) bs[j] = 0;
            primes.push_back(i);
        }
}

map<int, int> m;

void prime_factors(int a) {
    for (int i = 0; i < primes.size(); i++) {
        int p = primes[i];
        if (a%p==0) {
            while (a%p==0) a/=p;
            m[p]++;
        }
    }
    if (a!=1) m[a]++;
}

int arr[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int g = arr[0];
    for (int i = 0; i < n; i++) g = gcd(arr[i], g);
    for (int i = 0; i < n; i++) arr[i] = arr[i]/g;

    sieve();
    for (int i = 0; i<n; i++) prime_factors(arr[i]);

    int ans = 1<<30;
    for (map<int,int>::iterator it = m.begin(); it != m.end(); it++)
        ans = min(ans, n-it->second);

    if (ans==1<<30) cout << "-1\n";
    else cout << ans << endl;
}