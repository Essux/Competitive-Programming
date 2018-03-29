/*
* Solution to Distinctive Character
* RPC 2018 - 2nd Activity
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>

using namespace std;

const int INF = 1<<30;

int main() {
    int n, k; cin >> n >> k;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    queue<bitset<20> > q;
    vector<int> d(1<<20, INF);
    for (int i = 0; i < n; i++) {
        bitset<20> b(s[i]), b2(b.to_ulong()<<(20-k));
        d[b2.to_ulong()] = 0;
        q.push(b2);
    }

    while(!q.empty()) {
        bitset<20> u = q.front(); q.pop();
        for (int i = 19; i >= 20-k; i--) {
            bitset<20> v = u;
            v[i] = !v[i];
            if (d[u.to_ulong()] + 1 < d[v.to_ulong()]) {
                q.push(v);
                d[v.to_ulong()] = d[u.to_ulong()] + 1;
            }
        }
    }
    int maxV = -1;
    bitset<20> maxN;
    for (int i = 0; i <= (1<<k)-1; i++) {
        bitset<20> ir(i), i2r(i<<(20-k));
        if (d[i<<(20-k)] > maxV) maxV = d[i<<(20-k)], maxN = i2r;
    }
    for (int i = 19; i >= 20-k; i--) {
        cout << maxN[i];
    }
    cout << endl;
}