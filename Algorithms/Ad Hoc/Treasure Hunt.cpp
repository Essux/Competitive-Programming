#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    int x, y;
    scanf("%d %d", &x, &y);
    cout << ((int) abs(x1 - x2)% x ==0 and (int) abs(y2 - y1) % y == 0
        and ((int) abs(x1 - x2) / x) % 2 == ((int) abs(y2 - y1) / y) %2 ? "YES" : "NO");
}