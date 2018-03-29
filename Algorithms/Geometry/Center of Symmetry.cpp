#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const double EPS = 1e-9;

struct point {
    int x, y;
    point() {x = y = 0;}
    point(int _x, int _y) : x(_x), y(_y) {}
};

struct point_d {
    double x, y;
    point_d() {x = y = 0;}
    point_d(double _x, double _y) : x(_x), y(_y) {}
    bool operator< (point_d other) const {
        if (fabs(x - other.x) > EPS) return x < other.x;
        if (fabs(y - other.y) > EPS) return y < other.y;
        return false;
    }
};

int main() {
    int c; cin >> c;
    while (c--) {
        int n; scanf("%d", &n);
        point points[n];
        set<point_d> s;
        double avgx = 0, avgy = 0;
        for (int i = 0; i < n; i++) {
            int x, y; scanf("%d %d", &x, &y);
            points[i] = point(x, y);
            s.insert(point_d(x, y));
            avgx += points[i].x;
            avgy += points[i].y;
        }

        avgx /= (double) n;
        avgy /= (double) n;

        bool symmetric = true;
        for (int i = 0; i < n; i++) {
            point_d sym;
            sym.x = 2*avgx - points[i].x;
            sym.y = 2*avgy - points[i].y;
            if (s.count(sym)==0) symmetric = false;
        }

        if (symmetric) printf("yes\n");
        else printf("no\n");
    }
}