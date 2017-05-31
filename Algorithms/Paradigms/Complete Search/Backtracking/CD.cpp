#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 20 + 3

typedef pair<int, int> mask_int;

int songs[MAXN];
int n, t;

mask_int backtrack(int mask, int sum, int pos){
    if (pos >= t) return mask_int(mask, sum);

    mask_int op1 = backtrack(mask, sum, pos+1);
    mask_int op2;
    if (sum + songs[pos]>n) op2 = mask_int(0, -1);
    else op2 = backtrack(mask | (1<<pos), sum + songs[pos], pos+1);
    
    return op1.second > op2.second ? op1 : op2;
}

int main(){
    while (scanf("%d", &n) != EOF){
        scanf("%d", &t);
        for (int i = 0; i<t; i++) scanf("%d", songs + i);

        mask_int ans = backtrack(0, 0, 0);
        for (int i = 0; i < t; i++) if (ans.first & (1<<i)) printf("%d ", songs[i]);
        printf("sum:%d\n", ans.second);
    }
}