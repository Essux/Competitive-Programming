#include <cstdio>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    while (n--){
        int a, b;
        scanf("%d %d", &a, &b);
        if (a >= b) printf("FunkyMonkeys\n");
        else printf("WeWillEatYou\n");
    }
}