#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int a, r;
        scanf("%d %d", &a, &r);
        string s;
        cin >> s;
        printf("%d ", a);
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < r; j++) printf("%c", s[i]);
        }
        printf("\n");
    }
}