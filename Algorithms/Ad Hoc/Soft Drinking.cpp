#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int drink = k * l;
    int limes = c * d;
    int salt = p;
    int ans = min(min(drink / nl, limes), salt / np);
    cout << (ans/n);
}