#include <cstdio>

using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int persons = 0;
    while (n--){
        int a;
        scanf("%d", &a);
        if (a + k <= 5) persons++;
    }
    printf("%d", persons / 3);
}