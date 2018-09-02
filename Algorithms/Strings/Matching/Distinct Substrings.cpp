// SPOJ Distinct Substrings - DISUBSTR
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 * 2 + 10;

int z[MAXN], n;
string s, stemp;
bool in[MAXN];

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
    int t; cin >> t;
    while (t--) {
        cin >> stemp;
        n = stemp.size();
        s += '\0';
        int ans = 0;
        for (int i = 0; i < stemp.size(); i++) {
            s = stemp.substr(i, stemp.size()-i);
            n = s.size();
            z_algo();
            int rep = 0;
            for (int j = 0; j < n; j++) rep = max(z[j], rep);
            ans += n-rep;
        }
        cout << ans << '\n';
    }
}