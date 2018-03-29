// Solution to UVa - 10263 Railway
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const double EPS = 1e-9;

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}

    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
        return x < other.x;
        return y < other.y;
    }
};

struct vec {
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y); }

vec scale(vec v, double s) {
    return vec(v.x * s, v.y * s); }

point translate(point p, vec v) {
    return point(p.x + v.x , p.y + v.y);}

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double distToLine(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) {
        c = point(a.x, a.y);
        return dist(p, a);
    }
    if (u > 1.0) {
        c = point(b.x, b.y);
        return dist(p, b);
    }
    return distToLine(p, a, b, c);
}

int main() {
    double x, y;
    while (cin >> x >> y) {
        point m(x, y);
        int n;
        scanf("%d", &n);
        n++;
        point points[n];
        for (int i = 0; i < n; i++) {
            int x1, y1; scanf("%d %d", &x1, &y1);
            points[i] = point(x1, y1);
        }

        point ans; double minDist = 1e18;
        for (int i = 0; i < n-1; i++) {
            point c;
            double dist = distToLineSegment(m, points[i], points[i+1], c);
            if (dist < minDist) {
                minDist = dist;
                ans = c;
            }
        }
        printf("%.4f\n%.4f\n", ans.x, ans.y);
    }
}