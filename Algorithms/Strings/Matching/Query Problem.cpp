//SPOJ - QUERYSTR - Query Problem
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 1000004

int z[MAXN], n;
string s;

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
    int T; scanf("%d", &T);
    while (T--) {
        cin >> s;
        reverse(s.begin(), s.end());
        n = s.size();
        int q; scanf("%d", &q);
        z_algo();
        z[0] = n;
        while (q--) {
            int a; scanf("%d", &a);
            printf("%d\n", z[n-a]);
        }
    }
}