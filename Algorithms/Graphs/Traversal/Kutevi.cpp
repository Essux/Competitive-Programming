#include <bits/stdc++.h>

using namespace std;

#define D(_x) cout << #_x":" << _x << endl;

int ang[12];
bool reach[365];

int main() {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    fill(reach, reach+360, false);
    for (int i = 0; i < n; i++) {
        cin >> ang[i];
        reach[ang[i]] = true;
        q.push(ang[i]);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < 360; i++) {
            if (reach[i]) {
                int v = (i + u)%360;
                if (!reach[v]) {
                    q.push(v);
                    reach[v] = true;
                }
            }
        }
    }

    while (k--) {
        int q; cin >> q;
        cout << (reach[q] ? "YES" : "NO") << endl;
    }
}