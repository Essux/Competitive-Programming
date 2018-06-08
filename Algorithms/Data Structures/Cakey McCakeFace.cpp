// Cakey McCakeFace (Kattis)

#include <iostream>
#include <unordered_map>

using namespace std;

#define D(_x) cout << #_x":" << _x << endl;

const int MAXN = 2005;

int a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (b[j]-a[i]>=0)
                    mp[b[j]-a[i]]++;

        int maxT = -1, maxA = 0;
        for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            if (it->second > maxT) {
                maxT = it->second;
                maxA = it->first;
            }
            else if (it->second == maxT) {
                maxA = min(it->first, maxA);
            }
        }
        cout << maxA << endl;
    }
}