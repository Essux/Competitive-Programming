// Kattis - Elementary Math
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

const int MAXN = 2500 + 5;

vector<int> match, vis, matchLeft;
vector<int> graph[MAXN];

int Aug(int l) {
    if (vis[l]) return 0;
    vis[l] = 1;
    for (int j = 0; j < graph[l].size(); j++) {
        int r = graph[l][j];
        if (match[r] == -1 || Aug(match[r])) {
            match[r] = l;
            matchLeft[l] = r;
            return 1;
        }
    }
    return 0;
}

vector<ii> nums;
map<ll, int> res_id;
int res_count = 0;
vector<ll> id_res;

int getId (ll n) {
    if (res_id.count(n)==0) {
        id_res.push_back(n);
        return res_id[n] = res_count++;
    }
    return res_id[n];
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        nums.push_back(ii(a, b));

        graph[i].push_back(getId(a+b));
        graph[i].push_back(getId(a-b));
        graph[i].push_back(getId(a*b));
    }

    int MCBM = 0;
    match.assign(res_count, -1);
    matchLeft.assign(n, -1);
    for (int l = 0; l < n; l++) {
        vis.assign(n, 0);
        MCBM += Aug(l);
    }

    if (MCBM < n) {
        printf("impossible\n");
        return 0;
    }

    for (int l = 0; l < n; l++) {
        ll rval = id_res[matchLeft[l]];
        ll a = nums[l].first;
        ll b = nums[l].second;
        if (a+b==rval) printf("%lld + %lld = %lld\n", a, b, rval);
        else if (a-b==rval) printf("%lld - %lld = %lld\n", a, b, rval);
        else  printf("%lld * %lld = %lld\n", a, b, rval);
    }
}