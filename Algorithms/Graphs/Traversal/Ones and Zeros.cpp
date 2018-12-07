// SPOJ ONEZERO
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20000 + 5;

char add[MAXN];
int p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        memset(add, 0, sizeof(add));
        memset(p, -1, sizeof(p));
        int a; cin >> a;
        queue<int> q;
        q.push(1);
        add[1] = '1';
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (cur%a==0) {
                string ans;
                while (cur!=-1) {
                    ans.push_back(add[cur]);
                    cur = p[cur];
                }
                reverse(ans.begin(), ans.end());
                cout << ans << endl;
                break;
            }
            else {
                int next = (cur*10)%a;
                if (add[next]==0) {
                    q.push(next);
                    add[next] = '0';
                    p[next] = cur;
                }
                next = (cur*10 + 1)%a;
                if (add[next]==0) {
                    q.push(next);
                    add[next] = '1';
                    p[next] = cur;
                }
            }
        }
    }
}