//UVa - 10298 - Power Strings
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define MAXN 2000007

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
    while (getline(cin, s)) {
        if (s[s.size()-1]=='\r') s = s.substr(0, s.size()-1);
        if (s==".") return 0;
        s += s;
        n = s.size();
        z_algo();
        int matches = 0;
        for (int i = 0; i < n; i++)
            if (z[i] >= n/2) matches++;
        printf("%d\n", matches);
    }
}