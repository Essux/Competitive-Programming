// Codeforces Beta Round #9 (Div. 2 Only) A - Die Roll
#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int x = max(a, b);

    switch (x) {
        case 6:
            printf("1/6\n");
            break;

        case 5:
            printf("1/3\n");
            break;

        case 4:
            printf("1/2\n");
            break;

        case 3:
            printf("2/3\n");
            break;

        case 2:
            printf("5/6\n");
            break;

        case 1:
            printf("1/1\n");
            break;
    }
}