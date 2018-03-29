#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100010

string P, R;
int m;
int b[MAXN];

void kmpPreprocess() {
    int i = 0, j = -1; b[0] = -1;
    while (i < m) {
        while (j>=0 && R[i]!=R[j]) j = b[j];
        i++; j++;
        b[i] = j;
    }
}

int kmpSearch() {
    kmpPreprocess();
    int i = 0, j = 0;
    while (i<m) {
        while (j>=0 && P[i]!=R[j]) j = b[j];
        i++; j++;
    }
    return j;
}

int main() {
    while (cin >> P) {
        m = P.length();
        R = P;
        for (int i= 0; i < P.size(); i++) R[i] = P[P.size()-i-1];
        fill(b, b+MAXN, 0);
        cout << P;
        int start = kmpSearch();
        for (int i = start; i < m; i++) printf("%c", R[i]);
        printf("\n");
    }
}