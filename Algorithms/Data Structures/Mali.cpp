/*
* Kattis - Mali
*/

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

const int MAXA = 102;

int t1[MAXA], t2[MAXA];
int t3[MAXA], t4[MAXA];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin >> n) {
        fill(t1, t1+MAXA, 0);
        fill(t2, t2+MAXA, 0);
        while (n--) {
            int a, b; cin >> a >> b;
            t1[a]++; t2[b]++;
            int i = 1, j = 100;
            int maxS = 0;
            copy(t1, t1+MAXA, t3);
            copy(t2, t2+MAXA, t4);
            while (i <= 100 && j >= 0) {
                if (min(t1[i], t2[j])==0) {
                    if (t1[i]==0) i++;
                    if (t2[j]==0) j--;
                }
                else {
                    maxS = max(maxS, i+j);
                    int minus = min(t1[i], t2[j]);
                    t1[i] -= minus;
                    t2[j] -= minus;
                }
            }
            cout << maxS << endl;
            copy(t3, t3+MAXA, t1);
            copy(t4, t4+MAXA, t2);
        }

    }
}