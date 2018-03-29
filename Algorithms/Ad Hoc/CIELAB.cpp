// CodeChef CIELAB
#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b; cin >> a >> b;
    string ans = to_string(a-b);
    string pre = ans.substr(0, ans.size()-1);
    int suf = ans[ans.size()-1]-'0';
    if (suf == 9) suf = 8;
    else suf++;
    cout << pre << suf;
}