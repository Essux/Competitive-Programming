#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        int c, v; cin >> c >> v;
        string s;
        while (c--) s.push_back('C');
        while (v--) s.push_back('V');
        int i = 0;
        do {
            if (i++!=0) printf(" ");
            cout << s;
        } while(next_permutation(s.begin(), s.end()));
        printf("\n");
    }
}