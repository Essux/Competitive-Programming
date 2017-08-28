#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        long long S;
        scanf("%lld", &S);
        S += 1;
        long long num = (S * S) - 1;
        cout << num << '\n';
    }
}