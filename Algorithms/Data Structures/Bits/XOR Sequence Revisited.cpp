// Solution to UVa - 13081 XOR Sequence Revisited
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long l, r;
        cin >> l >> r;
        if (l+1 < r) {
            printf("0\n");
            continue;
        }
        long long lans = 0;
        for (int i = 1; i < 60; i++) {
            long long rem = l % (1LL<<(i+1));
            if (rem % 2 == 0 && rem >= (1LL<<(i))) lans |= (1<<i);
        }
        long long rem1 = l % 4;
        if (rem1 == 0 || rem1 == 3) lans |= 1;

        long long rans = 0;
        for (int i = 1; i < 60; i++) {
            long long rem = r % (1LL<<(i+1));
            if (rem % 2 == 0 && rem >= (1LL<<(i))) rans |= (1<<i);
        }
        rem1 = r % 4;
        if (rem1 == 0 || rem1 == 3) rans |= 1;
        cout << (lans&rans) << '\n';
    }
}