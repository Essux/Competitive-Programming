#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        int ans = abs((d+a)-(b+c));
        printf("%d\n", ans);
    }
}