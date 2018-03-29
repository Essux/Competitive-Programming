#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

double hypotenuse(double a, double b) {
    return sqrt(a*a + b*b);
}

struct point {
    int x, y;
    point() {x, y = 0;}
    point(int _x, int _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        return x < other.x;
    }
};

int main() {
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int N;
        scanf("%d", &N);
        point points[N];
        for (int i = 0; i < N; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            points[i] = point(x, y);
        }
        sort(points, points+N);
        int maxY = 0;
        double sum = 0;
        for (int i = N-2; i >= 0; i--) {
            point curPoint = points[i];
            point prevPoint = points[i+1];

            if (maxY >= curPoint.y) continue;
            double l1 = (prevPoint.x - curPoint.x) * (curPoint.y - maxY);
            l1 /= (double) (curPoint.y - prevPoint.y);

            double l2 = curPoint.y - maxY;
            sum += hypotenuse(l1, l2);
            maxY = curPoint.y;
        }
        printf("%.2f\n", sum);
    }
}