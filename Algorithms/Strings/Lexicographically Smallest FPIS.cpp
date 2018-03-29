// Solution to UVa - 13088 Lexicographically Smallest FPIS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    while (n--) {
        string S; cin >> S;
        int times[26];
        fill(times, times+26, 0);
        for (int i = 0; i < S.size(); i++) times[S[i]-'a']++;
        int extra = 0;
        for (int i = 0; i < 26; i++) {
            if (times[i]>1) {
                extra += times[i]-1;
                times[i] = 1;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (times[i]>0) {
                while (extra--) printf("%c", i+'a');
                extra = 0;
                printf("%c", i+'a');
            }
        }
        printf("\n");
    }
}