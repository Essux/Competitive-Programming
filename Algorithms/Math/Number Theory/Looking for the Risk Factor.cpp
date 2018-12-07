// Looking for the Risk Factor - Latin America Regionals 2018
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;

const int MAXN = 1e5 + 5;

bitset<MAXN + 5> bs;
vector<int> primes;
ll maxfactor[MAXN];

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < MAXN; i++)
        if (bs[i]) {
            for (ll j = i; j < MAXN; j += i) {
                bs[j] = 0;
                maxfactor[j] = max(maxfactor[j], i);
            }
            primes.push_back(i);
        }
}

struct query {int n, k, i, ans;};

bool initial_order(const query &a, const query &b) {
    if (a.k!=b.k) return a.k < b.k;
    return a.n < b.n;
}

bool print_order(const query &a, const query &b) {
    return a.i < b.i;
}

const int MAXQ = 5e4 + 15;
query arr[MAXQ];

vector<int> nums[MAXN];

int main() {
    fill(maxfactor, maxfactor+MAXN, 1);
    sieve();
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int n, k; cin >> n >> k;
        arr[i].n = n;
        arr[i].k = k;
        arr[i].i = i;
    }

    map<int, int> primeid;
    for (int i = 0; i < primes.size(); i++)
        primeid[primes[i]] = i;

    for (int i = 2; i < MAXN; i++)
        nums[primeid[maxfactor[i]]].push_back(i);

    sort(arr, arr+q, initial_order);
    int pos = 0, prime_pos = 0;
    ordered_set os;
    while (pos < q) {
        while (arr[pos].k >= primes[prime_pos]) {
            for (int i = 0; i < nums[prime_pos].size(); i++)
                os.insert(nums[prime_pos][i]);
            prime_pos++;
        }
        arr[pos].ans = os.order_of_key(arr[pos].n+1);
        pos++;
    }

    sort(arr, arr+q, print_order);
    for (int i = 0; i < q; i++)
        cout << arr[i].ans << endl;
}