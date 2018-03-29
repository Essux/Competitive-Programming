#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define D(_x) cout << #_x": " << _x << endl;

const double PI = acos(-1.0);
const double EPS = 1e-9;

double degToRad(double deg) {
    return deg * PI / 180.0;
}

int main() {
    double l, w, h, t;
    while (cin >> l >> w >> h >> t) {
        double x = l * sin(degToRad(t)) / sin(degToRad(90.0-t));
        double full, empty;
        if (x < h + EPS) {
            empty = (x * l / 2.0) * w;
            full = (l * w * h);
            full -= empty;
        }
        else {
            double y = h * sin(degToRad(90.0-t)) / sin(degToRad(t));
            full = (y * h / 2.0) * w;
        }
        printf("%.3f mL\n", full);
    }
}
