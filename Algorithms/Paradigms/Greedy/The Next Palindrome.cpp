// SPOJ The Next Palindrome - PALIN
#include <bits/stdc++.h>

using namespace std;

string s;

char nextC (char c) {
    return c=='9' ? '0' : c+1;
}

int main() {
    int n; cin >> n;
    while (n--) {
        cin >> s;
        int len = s.size();
        bool nine = true;
        for (int i = 0; i < len && nine; i++)
            if (s[i]!='9') nine = false;
        bool augm = true;
        for (int i = len/2 + len%2; i < len; i++) {
            int j = len-i-1;
            if (s[i]>s[j]) augm = true;
            if (s[i]<s[j]) augm = false;
            if (s[i]!=s[j]) break;
        }
        for (int i = len/2 + len%2 - 1; i >= 0; i--) {
            int j = len-i-1;
            if (augm) s[i] = nextC(s[i]);
            s[j] = s[i];
            augm = augm && (s[i]=='0');
        }
        if (nine) {
            cout << '1';
            for (int i = 0; i < len-1; i++) cout << '0';
            cout << "1\n";
        }
        else cout << s << endl;
    }
}