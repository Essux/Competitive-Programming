#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define MAXN 103
const double EPS = 1e-9;

#define D(_x) cout << #_x": " << _x << endl;

struct point {
    double x, y;
    point() {x = y = 0;}
    point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point a, point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}

bool insideCircle(point p, point c, double r) {
    double dx = p.x - c.x, dy = p.y - c.y;
    double Euc = dx * dx + dy * dy, rSq = r * r;
    return Euc < rSq + EPS;
}

point points[MAXN];

int main() {
    int n;
    while (scanf("%d", &n)!=EOF && n) {
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            points[i] = point(x, y);
        }
        double r; cin >> r;
        bool in = false;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                point c1, c2;
                bool existC1 = circle2PtsRad(points[i], points[j], r, c1);
                bool existC2 = circle2PtsRad(points[j], points[i], r, c2);
                bool curIn1 = true, curIn2;
                for (int k = 0; k < n; k++) {
                    bool inC1 = existC1 && insideCircle(points[k], c1, r);
                    bool inC2 = existC2 && insideCircle(points[k], c2, r);
                    curIn1 = curIn1 && inC1;
                    curIn2 = curIn2 && inC2;
                }
                in = in || curIn1 || curIn2;
            }
        }
        if (in) printf("The polygon can be packed in the circle.\n");
        else printf("There is no way of packing that polygon.\n");
    }
}