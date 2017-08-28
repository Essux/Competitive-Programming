#include <cstdio>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        int N;
        scanf("%d", &N);
        long long sum = 1;
        for (int i = 2; i<N; i++){
            if (N%i==0) sum += i;
        }
        if (sum > N) printf("abundant\n");
        else if (sum < N) printf("deficient\n");
        else printf("perfect\n");
    }
}