#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define D(_x) //cout << #_x":" << _x << endl; 
#define INF 1152921504606846976

typedef pair<double, double> interval;

double eps = 1e-6;

interval intersect(interval a, interval b){
    return interval(max(a.first, b.first), min(a.second, b.second));
}

int main(){
    int N; scanf("%d", &N);
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    bool corr = true;
    if (x1==x2 or y1 == y2) corr = false;
    x1 += eps;
    x2 -= eps;
    y1 += eps;
    y2 -= eps;
    interval res = interval((double) (-INF), (double) (INF));
    while (N-- and corr){
        int rx, ry, vx, vy;
        scanf("%d %d %d %d", &rx, &ry, &vx, &vy);
        double t1x = (double)(x1 - rx) / (double) vx;
        double t2x = (double)(x2 - rx) / (double) vx;
        double t1y = (double)(y1 - ry) / (double) vy;
        double t2y = (double)(y2 - ry) / (double) vy;
        if (max(t1x, t2x)<0 || max(t1y, t2y)<0) corr = false;
        
        interval ix;
        t1x = max(t1x, 0.0);
        t2x = max(t2x, 0.0);
        ix = interval(min(t1x, t2x), max(t1x, t2x));

        interval iy;
        t1y = max(t1y, 0.0);
        t2y = max(t2y, 0.0);
        iy = interval(min(t1y, t2y), max(t1y, t2y));      
    
        interval cur = intersect(ix, iy);
        res = intersect(cur, res);
        if (res.first > res.second) corr = false;
    }
    cout.precision(8);
    if (corr) cout << res.first;
    else cout << -1;
}