// SPOJ A Game With Numbers - NGM
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    if (s[s.size()-1]!='0') cout << "1\n" << s[s.size()-1];
    else cout << "2";
}