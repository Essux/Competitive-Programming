#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double PI = acos(-1.0);

double perimeter(double a, double b, double c) {
    return a + b + c;
}

double area(double a, double b, double c) {
    double s = perimeter(a, b, c) * 0.5;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}

double rInCircle(double a, double b, double c) {
    return area(a, b, c) / (0.5 * perimeter(a, b, c));
}

double rCircumCircle (double a, double b, double c) {
    return a * b * c / (4 * area(a, b, c));
}

double circleArea (double r) {
    return PI * r * r;
}

int main() {
    int a, b, c;
    while (scanf("%d %d %d", &a, &b, &c) != EOF) {
        double roses = circleArea(rInCircle(a, b, c));
        double violets = area(a, b, c) - roses;
        double sunflowers = circleArea(rCircumCircle(a, b, c)) - violets - roses;
        printf("%.4f %.4f %.4f\n", sunflowers, violets, roses);
    }
}