#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const double EPS = 1e-11;

struct point {
    double x, y; int z;
    point() { x = y = 0.0; z = 0;}
    point(double _x, double _y, int _z) : x(_x), y(_y), z(_z){}
    bool operator <(point other) const;
};

const point ORIGIN = point(0, 0, 0);
const point REF = point(1, 0, 0);


struct vec {
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y); }

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > -EPS; }

double angle(point a, point o, point b) { // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    double corr = (ccw(a, o, b))? 1 : -1;
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob))) * corr;
}

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

bool point::operator<(point other) const {
    double my_angle = angle(REF, ORIGIN, *this);
    double other_angle = angle(REF, ORIGIN, other);

    if (fabs(my_angle - other_angle) > EPS) return my_angle < other_angle;
    return dist(ORIGIN, *this) < dist(ORIGIN, other);
}

bool cmp(const point& a, const point& b) {
    if (fabs(a.x - b.x) > EPS) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    int n, ncase = 1;
    while (scanf("%d", &n)!= EOF && n) {
        point points[n];
        for (int i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            points[i] = point(x, y, z);
        }
        sort(points, points+n);

        double prevAngle = angle(REF, ORIGIN, points[0]);
        int maxZ = points[0].z;
        vector<point> invisible;
        for (int i = 1; i < n; i++) {
            double curAngle = angle(REF, ORIGIN, points[i]);
            if (fabs(prevAngle - curAngle) < EPS) {
                if (points[i].z <= maxZ) invisible.push_back(points[i]);
                maxZ = max(maxZ, points[i].z);
            }
            else {
                prevAngle = curAngle;
                maxZ = points[i].z;
            }
        }

        printf("Data set %d:\n", ncase++);
        if (invisible.size()==0) {
            printf("All the lights are visible.\n");
        }
        else {
            sort(invisible.begin(), invisible.end(), cmp);
            printf("Some lights are not visible:\n");
            for (int i = 0; i < invisible.size(); i++) {
                char c = (i==invisible.size()-1) ? '.' : ';';
                printf("x = %d, y = %d%c\n", (int) invisible[i].x, (int) invisible[i].y, c);
            }
        }
    }
}