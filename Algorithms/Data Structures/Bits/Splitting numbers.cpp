#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    while (cin >> n && n){
        bool even = true;
        int a = 0, b = 0; 
        for (int i = 0; i < 31; i++){
            if (n & (1<<i)){
                if (even) a |= (1<<i);
                else b |= (1<<i);
                even = !even;
            }
        }
        printf("%d %d\n", a, b);
    }
}