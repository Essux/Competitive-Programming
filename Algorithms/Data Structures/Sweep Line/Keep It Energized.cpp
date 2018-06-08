// UVa - Keep It Energized

#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

const int MAXN = 1e5 + 5;

struct shop {
    ll s;
    int c, id;
    shop() {}
    shop(ll _s, int _c, int _id) : s(_s), c(_c), id(_id) {}
};

ll E[MAXN];
shop sh_id[MAXN];
vector<shop> shops[MAXN];

int main() {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i <= n; i++) shops[i].clear();
        for (int i = 0; i < n; i++) cin >> E[i];
        for (int i = 1; i < n; i++) E[i] += E[i-1];
        for (int i = 0; i < m; i++) {
            int l, s, c; cin >> l >> s >> c;
            l--;
            shops[l].push_back(shop(s, c, i));
            sh_id[i] = shop(s, c, i);
        }


        multiset<int> v;
        multiset<ii> lim;
        for (int j = 0; j < shops[0].size(); j++) {
            shop sh = shops[0][j];
            lim.insert(ii(sh.s, sh.id));
            v.insert(sh.c);
        }

        for (int i = 0; i < n; i++) {
            multiset<ii>::iterator it = lim.upper_bound(ii(E[i], -1));
            for (multiset<ii>::iterator it2 = lim.begin(); it2!=it; it2++) {
                multiset<int>::iterator it_v;
                it_v = v.find(sh_id[it2->second].c);
                v.erase(it_v);
            }
            lim.erase(lim.begin(), it);

            if (v.empty()) break;
            int minCost = *v.begin();

            ll strengthToI = E[i];
            for (int j = 0; j < shops[i+1].size(); j++) {
                shop sh = shops[i+1][j];
                lim.insert(ii(sh.s+strengthToI, sh.id));
                v.insert(sh.c+minCost);
                sh_id[sh.id].c += minCost;
            }
        }
        if (v.empty()) cout << -1 << endl;
        else cout << *v.begin() << endl;
    }
}