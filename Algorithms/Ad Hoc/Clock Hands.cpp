#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int h, m; char trash;
    while (cin >> h >> trash >> m){
        if (h==0 && m==0) return 0;
        h = h*60 + m;
        double x = h/2.0;
        double y = m*6;
        double ans = fabs(x-y);
        ans = min(ans, 360.0-ans);
        printf("%.3f\n", (double)ans);
    }
}