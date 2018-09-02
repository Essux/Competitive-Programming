// UVa 13024 - Saint John Festival
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4 + 4;
const double EPS = 1e-9;

typedef long long ll;

int l, s;

struct point {
    ll x, y, value;
    point() {}
    point(ll _x, ll _y) : x(_x), y(_y) {}
    bool operator< (point other) const {
        if (x != other.x) return x < other.x;
        return y <= other.y;
    }
    bool operator!= (point other) const {
        return x!=other.x || y !=other.y;
    }
};

point toVec(point a, point b) {
    return point(b.x - a.x, b.y - a.y);
}

ll cross (point a, point b) {
    return a.x * b.y - a.y * b.x;
}

ll ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r));
}

vector<point> convex_hull(vector<point> &pts) {
    sort(pts.begin(), pts.end());
    vector<point> H;

    for (int phase = 0; phase < 2; phase++) {
        int start = H.size();
        for (int i = 0; i < pts.size(); i++) {
            while (H.size() >= start+2 && ccw(H[H.size()-2], H[H.size()-1], pts[i]) <= 0)
                H.pop_back();
            H.push_back(pts[i]);
        }

        H.pop_back();
        reverse(pts.begin(), pts.end());
    }
    return H;
}

void preprocess(vector<point> &pts, int &imin, int &imax) {
    imin = 0, imax = 0;
    for (int i = 0; i < pts.size(); i++) {
        if (pts[i].x <= pts[imin].x)
            if (pts[i].x < pts[imin].x || pts[i].y >= pts[imin].y) imin = i;

        if (pts[i].x >= pts[imax].x)
            if (pts[i].x > pts[imax].x || pts[i].y <= pts[imax].y) imax = i;
    }
}

bool cmp(point a, point b) {
    return a.x < b.x;
}

vector<point> L, S;

int main() {
    while (cin >> l) {
        L.clear(); S.clear();
        for (int i = 0; i < l; i++) {
            ll x, y; cin >> x >> y;
            L.push_back(point(x, y));
        }
        cin >> s;
        for (int i = 0; i < s; i++) {
            ll x, y; cin >> x >> y;
            S.push_back(point(x, y));
        }

        vector<point> hull = convex_hull(L);

        int imin, imax;
        preprocess(hull, imin, imax);
        vector<point> d1, d2;
        int _i = imin;
        while (_i!=imax) {
            d1.push_back(hull[_i]);
            _i = (_i+1)%hull.size();
        } d1.push_back(hull[_i]);

        while (_i!=imin) {
            d2.push_back(hull[_i]);
            _i = (_i+1)%hull.size();
        } d2.push_back(hull[_i]);

        if (d1[0]!=hull[imin]) reverse(d1.begin(), d1.end());
        if (d2[0]!=hull[imin]) reverse(d2.begin(), d2.end());

        int timesmin = 0;
        point extramin;
        for (int i = 0; i < hull.size(); i++)  {
            if (hull[i].x==hull[imin].x) {
                if (i != imin) extramin = hull[i];
                timesmin++;
            }
        }

        int ans = 0;
        for (int i = 0; i < s; i++) {
            if (S[i].x < hull[imin].x || S[i].x > hull[imax].x) continue;

            vector<point>::iterator it;
            it = lower_bound(d1.begin(), d1.end(), S[i], cmp);
            point a = *it, b = *(--it);
            double limA = (double) ((b.y-a.y)*(S[i].x-a.x)) / (double) (b.x-a.x);
            limA += a.y;

            it = lower_bound(d2.begin(), d2.end(), S[i], cmp);
            a = *it, b = *(--it);
            double limB = (double) ((b.y-a.y)*(S[i].x-a.x)) / (double) (b.x-a.x);
            limB += a.y;

            if (S[i].x == hull[imin].x) {
                if (timesmin==1) limA = limB = hull[imin].y;
                else {
                    limA = hull[imin].y;
                    limB = extramin.y;
                }
            }

            double up = max(limA, limB), lo = min(limA, limB);
            if (S[i].y <= up+EPS && S[i].y >= lo-EPS) ans++;
        }
        printf("%d\n", ans);
    }
}