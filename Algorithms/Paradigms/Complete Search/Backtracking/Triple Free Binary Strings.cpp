#include <bits/stdc++.h>

using namespace std;

int n; string str;
int sec[3];

int back(int id, int mask) {
    if (id>=n) return 1;
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        if (str[id]=='0'+i || str[id]=='*') {
            bool ok = true;
            for (int sz = 1; sz*3 <= id+1; sz++) {
                int nmask = (mask << 1) | i;
                for (int j = 0; j < 3; j++) {
                    sec[j] = nmask & ((1<<sz)-1);
                    nmask >>= sz;
                }
                if (sec[0]==sec[1] && sec[1]==sec[2]) {ok = false; break;}
            }
            if (ok) ans += back(id+1, (mask<<1) | i);
        }
    }
    return ans;
}

int main() {
    int ncase = 1;
    while (cin >> n && n) {
        cin >> str;
        printf("Case %d: %d\n", ncase++, back(0, 0));
    }
}