#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define EPS 1e-9

struct point {
    double x, y;
    point() {x = y = 0.0;}
    point(double _x, double _y) : x(_x), y(_y) {}
};

struct line {
    double a, b, c;
    line() {a = b = c = 0;}
};

void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) {l.a = 1.0; l.b = 0.0; l.c = -p1.x;}
    else {
        l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double) (l.a * p1.x) - p1.y;
    }
}

void intersection(line l1, line l2, point &p) {
    p.x = (l2.b * l1. c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
}

point halfPoint(point a, point b) {
    return point((a.x + b.x) / 2.0, (a.y + b.y) / 2.0);
}

double area(vector<point> &P) {
    double ans = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < P.size()-1; i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        ans += (x1 * y2 - x2 * y1);
    }
    return fabs(ans) / 2.0;
}

double perimeter(vector<point> &P) {
    double ans = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < P.size()-1; i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        ans += hypot(x1 - x2, y1 - y2);
    }
    return ans;
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int ncase; scanf("%d", &ncase);
        double Bx, Cx, Cy, Dx, Dy;
        cin >> Bx >>Cx >>Cy >>Dx >>Dy;
        vector<point> points;
        points.push_back(point());
        points.push_back(point(Bx, 0));
        points.push_back(point(Cx, Cy));
        points.push_back(point(Dx, Dy));

        vector<point> semipoints;
        semipoints.push_back(halfPoint(points[1], points[2]));
        semipoints.push_back(halfPoint(points[2], points[3]));
        semipoints.push_back(halfPoint(points[3], points[0]));
        semipoints.push_back(halfPoint(points[0], points[1]));

        vector<line> divisions;
        line l1, l2, l3, l4;
        pointsToLine(points[0], semipoints[0], l1);
        pointsToLine(points[1], semipoints[1], l2);
        pointsToLine(points[2], semipoints[2], l3);
        pointsToLine(points[3], semipoints[3], l4);
        divisions.push_back(l1);
        divisions.push_back(l2);
        divisions.push_back(l3);
        divisions.push_back(l4);

        vector<point> quad;
        point a1, b1, c1, d1;
        intersection(divisions[0], divisions[1], a1);
        intersection(divisions[1], divisions[2], b1);
        intersection(divisions[2], divisions[3], c1);
        intersection(divisions[3], divisions[0], d1);
        quad.push_back(a1);
        quad.push_back(b1);
        quad.push_back(c1);
        quad.push_back(d1);
        quad.push_back(a1);

        vector<point> tri1;
        tri1.push_back(points[0]);
        tri1.push_back(points[1]);
        tri1.push_back(quad[0]);
        tri1.push_back(points[0]);
        vector<point> tri2;
        tri2.push_back(points[1]);
        tri2.push_back(points[2]);
        tri2.push_back(quad[1]);
        tri2.push_back(points[1]);
        vector<point> tri3;
        tri3.push_back(points[2]);
        tri3.push_back(points[3]);
        tri3.push_back(quad[2]);
        tri3.push_back(points[2]);
        vector<point> tri4;
        tri4.push_back(points[3]);
        tri4.push_back(points[0]);
        tri4.push_back(quad[3]);
        tri4.push_back(points[3]);

        /*for (int i = 0; i < tri1.size(); i++) {
            printf("%.3f %.3f\n", tri1[i].x, tri1[i].y);
        }
        for (int i = 0; i < tri2.size(); i++) {
            printf("%.3f %.3f\n", tri2[i].x, tri2[i].y);
        }
        for (int i = 0; i < tri3.size(); i++) {
            printf("%.3f %.3f\n", tri3[i].x, tri3[i].y);
        }
        for (int i = 0; i < tri4.size(); i++) {
            printf("%.3f %.3f\n", tri4[i].x, tri4[i].y);
        }*/

        printf("%d ", ncase);
        printf("%.3f ", area(tri1) / 160.0);
        printf("%.3f ", area(tri2) / 160.0);
        printf("%.3f ", area(tri3) / 160.0);
        printf("%.3f ", area(tri4) / 160.0);
        printf("%.3f ", area(quad) / 160.0);
        printf("%d\n", (int) ceil(perimeter(quad) * 16.5));
    }

}