#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 1005

string T;
int n;
int RA[MAXN], tempRA[MAXN];
int SA[MAXN], tempSA[MAXN];
int c[MAXN];
int Phi[MAXN], LCP[MAXN], PLCP[MAXN];
int owner[MAXN];

void countingSort(int k) {
    int i, sum, maxi = max(300, n);
    memset(c, 0, sizeof c);
    for (i = 0; i < n; i++)
        c [i + k < n ? RA[i+k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t; }
    for (i = 0; i < n; i++)
        tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n; i++) SA[i] = tempSA[i];
}

void constructSA() {
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];
    for (i = 0; i < n; i++) SA[i] = i;
    for (k = 1; k < n; k <<= 1) {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        for (i = 1; i < n; i++)
            tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; i++) RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;
    }
}

void computeLCP() {
    int i, L;
    Phi[SA[0]] = -1;
    for (i = 1; i < n; i++) Phi[SA[i]] = SA[i-1];
    for (i = L = 0; i < n; i++) {
        if (Phi[i] == -1) { PLCP[i] = 0; continue;}
        while (T[i+L] == T[Phi[i] + L]) L++;
        PLCP[i] = L;
        L = max(L-1, 0);
    }
    for (i = 0; i < n; i++) LCP[i] = PLCP[SA[i]];
}

int main() {
    string S;
    int ncase = 0;
    while (cin >> T >> S) {
        if (ncase++>0) printf("\n");
        int first_size = T.size();
        T += "$";
        T += S;
        T += "#";
        n = T.size();
        constructSA();
        computeLCP();
        for (int i = 0; i < n; i++) {
            owner[i] = (SA[i]<=first_size) ? 1:2;
        }

        int maxLCP = 0;
        for (int i = 1; i < n; i++) {
            if (owner[i]!=owner[i-1] && LCP[i]>maxLCP) maxLCP = LCP[i];
        }

        if (maxLCP == 0){
            printf("No common sequence.\n");
            continue;
        }
        bool rep = false;
        for (int i = 1; i < n; i++) {
            if (rep) {
                if (LCP[i]<maxLCP) rep = false;
            }
            else {
                if (owner[i]!=owner[i-1] && LCP[i]==maxLCP) {
                    cout << T.substr(SA[i], maxLCP) << '\n';
                    rep = true;
                }
            }
        }
    }
}