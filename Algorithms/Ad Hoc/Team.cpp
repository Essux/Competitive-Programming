#include <cstdio>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int sols = 0;
    while (N--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a+b+c >= 2) sols++;
    }
    printf("%d", sols);
}