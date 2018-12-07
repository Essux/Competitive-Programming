// Codeforces Round #115 - Robot Bicorn Attack
#include <bits/stdc++.h>

using namespace std;

const int MAX_SCORE = 1000000;
string s;

int st_val(int i, int j) {
    if (j-i>0 && s[i]=='0') return -1;
    string s2 = s.substr(i, j-i+1);
    try {
        int val = stoi(s2);
        if (val > MAX_SCORE) return -1;
        return val;
    } catch (out_of_range ex) {
        return -1;
    }
}

int main() {
    cin >> s;
    int n = s.size();
    int ans = -1;
    for (int i = 0; i < n; i++) {
        int cur1 = st_val(0, i);
        if (cur1 < 0) continue;
        for (int j = i+1; j < n-1; j++) {
            int cur2 = st_val(i+1, j);
            int cur3 = st_val(j+1, s.size()-1);
            if (cur2 < 0) continue;
            if (cur3 < 0) continue;
            ans = max(ans, cur1 + cur2 + cur3);
        }
    }
    printf("%d\n", ans);
}