#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int a, b;
    while (scanf("%d %d\n", &a, &b) != EOF){
        long ones = 0;
        while (a <= b){
            int t = a;
            while (t) {t -= t & (-t); ones++;}
            a++;
        }
        printf("%d", ones);
    }
}