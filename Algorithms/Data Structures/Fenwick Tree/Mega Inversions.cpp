// Kattis - Mega Inversions
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int arr[MAXN];
int n;

class FenwickTree {
    vector<ll> ft;
    public:
    FenwickTree(int sz) {ft.assign(sz+1, 0);}
    ll rsq(int b) {
        b = n+1-b;
        if (b==0) return 0;
        ll sum = 0;
        for (; b; b -= b & (-b)) sum += ft[b];
        return sum;
    }
    void adjust(int k, ll v) {
        k = n+1-k;
        for (; k<ft.size(); k += k & (-k)) ft[k] += v;
    }
};

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    FenwickTree accum(n), pairs(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += pairs.rsq(arr[i]+1);
        accum.adjust(arr[i], 1);
        pairs.adjust(arr[i], accum.rsq(arr[i]+1));
    }
    cout << ans << endl;
}