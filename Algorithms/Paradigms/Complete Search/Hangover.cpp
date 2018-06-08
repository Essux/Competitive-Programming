// SPOJ Hangover - HANGOVER
#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
    while(true){
        double c; cin >> c;
        if (c < EPS) break;
        double accum = 0;
        for (int i = 1; i <= 300; i++) {
            accum += 1.0/(double) (i+1);
            if (accum > c-EPS) {
                printf("%d card(s)\n", i);
                break;
            }
        }
    }
}