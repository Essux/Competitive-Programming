/*
* Kattis - Heart Rate
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        int b; double p;
        cin >> b >> p;
        printf("%.5f %.5f %.5f\n", (double)(b-1)/p*60.0, (double)b/p*60.0, (double)(b+1)/p*60.0);
    }
}