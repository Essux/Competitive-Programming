/*
* Solution to Galactic Collegiate Programming Contest
* RPC 2018 - 2nd Activity
*/

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int main() {
    int n, m; cin >> n >> m;
    vector<ii> score(n+1, ii(0, 0));
    multiset<ii> s;
    while (m--) {
        int t, p; cin >> t >> p;
        if (t==1) {
            score[t] = ii(score[t].first+1, score[t].second - p);
            s.erase(s.begin(), s.upper_bound(score[t]));
        }
        else {
            multiset<ii>::iterator it = s.find(ii(score[t]));
            if (it!=s.end()) s.erase(it);
            score[t] = ii(score[t].first+1, score[t].second - p);
            if (score[t] > score[1]) s.insert(score[t]);
        }
        cout << s.size()+1 << endl;
    }
}