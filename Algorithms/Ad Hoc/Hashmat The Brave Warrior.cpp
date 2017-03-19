#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    long a, b;
    while (cin >> a){
        cin >> b;
        long c = abs(a-b);
        printf("%ld\n", c);
    }
}