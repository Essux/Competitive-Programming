#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int N, D, R;
    while (scanf("%d %d %d", &N, &D, &R) != EOF and N){
        int day[N], night[N];
        for (int i = 0; i < N; i++) scanf("%d", day+i);
        for (int i = 0; i < N; i++) scanf("%d", night+i);
        sort(day, day+N), sort(night, night+N, greater<int>());
        int sum = 0;
        for (int i = 0; i< N; i++) sum += (day[i]+night[i]) > D ? (day[i]+night[i]) - D : 0;
        printf("%d\n", sum*R);
    }
}