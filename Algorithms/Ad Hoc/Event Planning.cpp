#include <cstdio>

using namespace std;

int main(){
    int N, B, H, W;
    while (scanf("%d %d %d %d", &N, &B, &H, &W) != EOF){
        int bestPrice = 1 << 30;
        while (H--){
            int price;
            scanf("%d", &price);
            int rooms;
            for (int i = 0; i < W; i++){
                scanf("%d", &rooms);
                if (rooms >= N)
                    if (N*price <= B)
                        if (N*price < bestPrice)
                            bestPrice = N*price;
            }
        }
        if (bestPrice == 1 << 30) printf("stay home\n");
        else printf("%d\n", bestPrice);
    }
}