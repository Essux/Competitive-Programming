// UVa 13257 - License Plates
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int fol[26][MAXN];

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        for (int i = 0; i < 26; i++) fol[i][n] = -1;

        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) fol[j][i] = fol[j][i+1];
            fol[s[i]-'A'][i] = i;
        }

        long long ans = 0;
        for (int i = 0; i < 26; i++) {
            int a = fol[i][0];
            if (a==-1) continue;
            for (int j = 0; j < 26; j++) {
                int b = fol[j][a+1];
                if (b==-1) continue;
                for (int k = 0; k < 26; k++) {
                    int c = fol[k][b+1];
                    ans += (c!=-1);
                }
            }
        }
        cout << ans << endl;
    }
}