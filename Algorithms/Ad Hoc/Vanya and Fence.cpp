#include <cstdio>

using namespace std;

int main(){
    int n, h;
    scanf("%d %d", &n, &h);
    int width = 0;
    for (int i = 0; i< n;i++){
        int a;
        scanf("%d", &a);
        if (a>h) width += 2;
        else width++;
    }
    printf("%d", width);
}