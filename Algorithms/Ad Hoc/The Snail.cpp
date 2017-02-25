#include <cstdio>

using namespace std;

int main(){
    int H, U, D, F;
    while (true){
        scanf("%d %d %d %d", &H, &U, &D, &F);
        if (H == 0) break;
        int day = 1;
        float currH = 0;
        float dailyF = (float) U * (float) F / 100.0;
        while (true){
            float dayU = U - dailyF * (day - 1);
            if (dayU > 0) currH += dayU;
            if (currH > H){
                printf("success on day %d\n", day);
                break;
            }
            currH -= D;
            if (currH < 0){
                printf("failure on day %d\n", day);
                break;
            }
            day++;
        }
    }
}