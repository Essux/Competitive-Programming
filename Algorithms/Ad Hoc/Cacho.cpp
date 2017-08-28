#include <cstdio>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        int prev, next;
        scanf("%d", &prev);
        bool error = false;
        for (int i = 0; i<4; i++){
            scanf("%d", &next);
            if (next != prev+1 and !error){
                printf("N\n");
                error = true;
            }
            prev = next;
        }
        if (!error) printf("Y\n");
    }
}