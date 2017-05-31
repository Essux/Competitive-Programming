#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define D(_x) //cout << #_x":" << _x << endl;

double maxL(double* arr, int size){
    double max = -1.0;
    for (int i = 0; i < size; i++){
        if (arr[i]> max) max = arr[i];
        D(arr[i]);
    }
    return max;
}

int main(){
    int f, r;
    while (scanf("%d", &f) and f){
        scanf("%d", &r);
        int fronts[f], rears[r];
        for (int i = 0; i < f; i++) scanf("%d", fronts+i); 
        for (int i = 0; i < r; i++) scanf("%d", rears+i);

        double quotients[f*r];
        for (int i = 0; i < f; i++){
            for (int j = 0; j < r; j++){
                quotients[r*i+j] = (double)rears[j] / (double)fronts[i];
            }
        }

        sort(quotients, quotients + f*r);
        double ratios[f*r - 1];
        for (int i = 0; i < f*r-1; i++){
            ratios[i] = quotients[i+1] / quotients[i];
        }
        printf("%.2f\n", maxL(ratios, f*r-1));
    }
}