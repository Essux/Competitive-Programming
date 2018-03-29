#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

#define D(_x) cout << #_x":" << _x << endl;

string st;

int main() {
    int n; cin >> n;
    for (int ncase = 1; ncase <= n; ncase++) {
        cin >> st;
        int f = 0;
        int h1 = 0, h2 = 0, h3 = 0;
        for (int i = 0; i < st.size(); i++) {
            char c = st[i];
            if (c == '^') {
                if (h2) h2--, f++;
                else if (h3 && f) h2++, h3--;
                else h1++;
            }
            else {
                if (h1) h2++, h1--;
                else if (f > h3) h3++;
            }
        }
        printf("Case %d: %d\n", ncase, f);
   }
}