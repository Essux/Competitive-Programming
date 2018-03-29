#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    long long n, t; char d;
    while (cin >> n >> t >> d) {
        string rubbish, st1, st;
        getline(cin, rubbish);
        getline(cin, rubbish);
        getline(cin, st1);
        getline(cin, rubbish);
        for (int i = 0; i < n; i++) {
            st += st1[2*i+1];
        }
        int pos[n];
        if (d=='R') {
            int delta = t%n;
            for (int i = 0; i < n; i++) {
                pos[(i+delta) % n] = i;
            }
        } else {
            int delta = t%n;
            for (int i = 0; i < n; i++) {
                pos[(i-delta+n) % n] = i;
            }
        }
        cout << rubbish << '\n';
        for (int i = 0; i < n; i++) {
            cout << '|' << st[pos[i]];
        }
        cout << "|\n" << rubbish << '\n';
    }
}