#include <iostream>
#include <string>

using namespace std;

int n, h;
string s;

void back(int i, int ones) {
    if (i >= n) {
        if (ones == h) cout << s << endl;
        return;
    }
    s[i] = '0';
    back(i+1, ones);
    if (ones < h) {
        s[i] = '1';
        back(i+1, ones+1);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> h;
        s.assign(n, '0');
        back(0, 0);
        if (t>0) cout << endl;
    }
}