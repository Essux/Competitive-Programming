#include <cstdio>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int a, b;
        scanf("%d %d", &a, &b);
        char ans;
        if (a > b) ans = '>';
        else if (a < b) ans = '<';
        else ans = '=';
        printf("%c\n", ans);
    }
}