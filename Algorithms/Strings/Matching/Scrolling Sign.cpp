#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 106

string P, T;
int m, n;
int b[MAXN];

void kmpPreprocess() {
    int i = 0, j = -1; b[0] = -1;
    while (i < m) {
        while (j>=0 && P[i]!=P[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

int kmpSearch() {
    kmpPreprocess();
    int i = 0, j = 0;
    n = T.size(); m = P.size();
    while (i<n) {
        while (j>=0 && T[i]!=P[j]) j = b[j];
        i++; j++;
    }
    return j;
}

int main() {
    int tests; cin >> tests;
    while (tests--) {
        int k, w, chars = 0;
        cin >> k >> w;
        cin >> P;
        chars += (int) P.size();
        while (--w) {
            T = P;
            cin >> P;
            chars += (int) P.size();
            int pos = kmpSearch();
            chars -= pos;
        }
        printf("%d\n", chars);
    }
}