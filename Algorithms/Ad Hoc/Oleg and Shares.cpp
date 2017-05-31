#include <cstdio>

using namespace std;

#define MAXN 100000 + 10
#define INF 1<<30

int nums[MAXN];

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    int min = INF;
    for (int i = 0; i < N; i++) {
       scanf("%d", nums + i);
       if (nums[i] < min) min = nums[i];
    }
    long long sum = 0;
    bool corr = true;
    for (int i = 0; i < N; i++){
        if ((nums[i] - min) % K == 0) sum += (nums[i] - min) / K;
        else {corr = false; break;}
    }
    cout <<  (corr ? sum : -1);
}