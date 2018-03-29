#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double pi = acos(-1.0);

struct point {
    double x, y;
    point() { x = y = 0.0;}
    point(double _x, double _y) : x(_x), y(_y) {}
    point operator-(point other) const {
        return point(x - other.x, y - other.y);
    }
    point operator+(point other) const {
        return point(x + other.x, y + other.y);
    }
};

point rotate(point p, double theta) {
    return point(p.x * cos(theta) - p.y * sin(theta),
                p.x * sin(theta) + p.y * cos(theta));
}

point midpoint(point a, point b) {
    return point((a.x+b.x)/2.0, (a.y+b.y)/2.0);
}

int main() {
    double x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        point a(x1, y1);
        point b(x2, y2);
        point mid = midpoint(a, b);
        a = a - mid;
        b = b - mid;
        point c = rotate(a, pi/2.0) + mid;
        point d = rotate(a, 3.0*pi/2.0) + mid;
        printf("%.10f %.10f %.10f %.10f\n", c.x, c.y, d.x, d.y);
    }
}