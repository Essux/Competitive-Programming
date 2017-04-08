#include <cstdio>
#include <complex>
#include <cmath>

using namespace std;

#define MAXN 30

int main(){
    complex<int> gaussians[MAXN];
    complex<int> identity (-1, 1);
    gaussians[0] = complex<int>(1,0);
    for (int i = 1; i < MAXN; i++) gaussians[i] = gaussians[i-1]*identity;

    int peano;
    while (scanf("%d", &peano) != EOF){
        complex<int> gaussian(0,0);
        for (int i = 0; i < MAXN; i++){
            if (peano & (1<<i)) gaussian += gaussians[i];
        } 
        printf("%d %d\n", gaussian.real(), gaussian.imag());
    }
}