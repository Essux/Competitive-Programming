// Codeforces Round #513 A - Phone Numbers
#include <stdio.h>

int main() {
    int n;
    scanf("%d\n", &n);
    int eight = 0;
    for (int i = 0; i < n; i++) {
        char c;
        scanf("%c", &c);
        if (c == '8') eight++;
    }
    int ans = 0;
    for (int i = 0; i <= eight; i++) {
        if ((n-i)/10 >= i) ans = i;
    }
    printf("%d\n", ans);
}