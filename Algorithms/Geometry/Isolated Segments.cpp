#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double EPS = 1e-9;

struct point {
    double x, y;
    point() { x = y = 0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};

struct line {
    double a, b, c;
};

struct square {
    point p1, p2;
    square(point a, point b) {
        if (fabs(a.x - b.x) < EPS) {
            if (a.y < b.y) p1 = a, p2 = b;
            else p1 = b, p2 = a;
        }
        else {
            if (a.x < b.x) p1 = a, p2 = b;
            else p1 = b, p2 = a;
        }
    }
    square() {
        point a; p1 = a;
        point b; p2 = b;
    }
};

void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

bool areParallel(line l1, line l2) {
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2) {
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return true;
}

bool inSquare(square s, point p) {
    double maxX = max(s.p1.x, s.p2.x);
    double minX = min(s.p1.x, s.p2.x);
    double maxY = max(s.p1.y, s.p2.y);
    double minY = min(s.p1.y, s.p2.y);
    //printf("%.2f %.2f in square %.2f %.2f %.2f %.2f\n", p.x, p.y, minX, minY, maxX, maxY);
    if (maxX + EPS > p.x && p.x > minX - EPS) {
        if (maxY + EPS > p.y && p.y > minY - EPS) {
            return true;
        }
        return false;
    }
    return false;
}

bool squaresIntersect(square a, square b) {
    double minXA = min(a.p1.x, a.p2.x);
    double maxXA = max(a.p1.x, a.p2.x);
    double minXB = min(b.p1.x, b.p2.x);
    double maxXB = max(b.p1.x, b.p2.x);

    bool xFine = (min(maxXA, maxXB) + EPS > max(minXA, minXB));

    double minYA = min(a.p1.y, a.p2.y);
    double maxYA = max(a.p1.y, a.p2.y);
    double minYB = min(b.p1.y, b.p2.y);
    double maxYB = max(b.p1.y, b.p2.y);

    bool yFine = (min(maxYA, maxYB) + EPS > max(minYA, minYB));
    return xFine && yFine;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        int x1, y1, x2, y2;
        line segments[n];
        square limits[n];
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            point a(x1, y1);
            point b(x2, y2);

            square s(a, b);
            limits[i] = s;

            line l;
            pointsToLine(a, b, l);
            segments[i] = l;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            bool isolated = true;
            for (int j = 0; j < n && isolated; j++) {
                if (i!=j) {
                    //printf("%d vs %d\n", i, j);
                    point p;
                    if (areSame(segments[i], segments[j]) && squaresIntersect(limits[i], limits[j])) isolated = false;
                    else if (areIntersect(segments[i], segments[j], p)) {
                        //printf("Intersection: %.2f %.2f\n", p.x, p.y);
                        //printf("Intersection in square %d\n", inSquare(limits[i], p));
                        //printf("Intersection in square %d\n", inSquare(limits[j], p));
                        if (inSquare(limits[i], p) && inSquare(limits[j], p)) isolated = false;
                    }
                }
            }
            ans += isolated ? 1 : 0;
        }
        printf("%d\n", ans);
    }
}