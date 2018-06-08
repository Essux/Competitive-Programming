#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const double EPS = 1e-7;

double logB(double y, double x) {
    return log(x) / log(y);
}

int main() {
    ll x, y; cin >> x >> y;
    if (x==1 && y==1) {printf("=\n"); return 0;}
    double a = y * logB(y, x);
    double b = x;
    if (abs(a-b)<EPS) printf("=\n");
    else if (a < b) printf("<\n");
    else printf(">\n");
}