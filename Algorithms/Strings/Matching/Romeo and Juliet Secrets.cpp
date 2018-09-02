// UVa 13258 - Romeo and Juliet Secrets
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 5;

string T, W, s;
int z[MAXN], z1[MAXN], z2[MAXN], n;

void z_algo() {
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
        } else {
            int k = i-L;
            if (z[k] < R-i+1) z[i] = z[k];
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                z[i] = R-L; R--;
            }
        }
    }
}

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int k;
        cin >> T >> W >> k;
        s = W + '#' + T + '$';
        n = s.size();
        z_algo();
        for (int i = 0; i < n; i++) z1[i] = z[i];

        reverse(W.begin(), W.end());
        reverse(T.begin(), T.end());
        s = W + '#' + T + '$';
        z_algo();
        for (int i = 0; i < n; i++) z2[i] = z[i];

        for (int i = 0; i < n; i++) z2[i] = z[i];
        int sz = T.size(), ans = 0, wsz = W.size();
        for (int i = 0; i+wsz-1 < sz; i++)
            ans += (z1[i+wsz+1]+z2[n-1-i-wsz]+k>=wsz);
        cout << ans << endl;
    }
}