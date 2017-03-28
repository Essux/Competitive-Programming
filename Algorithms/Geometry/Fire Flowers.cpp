#include <iostream>
#include <cmath>

using namespace std;

bool innerCircle(int r1, int x1, int y1, int r2, int x2, int y2){
    double d = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    if (r1 >= d + r2) return true;
    return false;
}

int main(){
    int r1, x1, y1;
    int r2, x2, y2;
    while (cin >> r1){
        cin >> x1 >> y1;
        cin >> r2 >> x2 >> y2;
        cout << (innerCircle(r1, x1, y1, r2, x2, y2) ? "RICO" : "MORTO") << '\n';
    }
}