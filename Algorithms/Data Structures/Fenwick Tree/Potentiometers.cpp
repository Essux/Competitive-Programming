#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

#define MAXN 200000 + 5

int F[MAXN];

int rsq(int k){
    int sum = 0;
    for (; k; k -=  k & (-k)) sum += F[k];
    return sum;
}

int rsq(int a, int b){
    return rsq(b) - (a <= 1 ? 0:rsq(a-1));
}

void adjust(int k, int v){
    for (; k < MAXN; k += k & (-k)) F[k] += v;
}

int main(){
    int n, ncase = 1;
    while (scanf("%d", &n) && n){
        for (int i = 0; i < MAXN; i++) F[i] = 0;
        for (int i =1; i<=n; i++){
            int p;            
            scanf("%d", &p);
            adjust(i, p);
        }

        if (ncase > 1) printf("\n");   
        printf("Case %d:\n", ncase);
        char action;
        while (scanf(" %c", &action) && action != 'E'){
            int a, b;
            cin >> a >> b;
            if (action == 'S') adjust(a, b - rsq(a, a));
            else cout << rsq(a, b) << '\n';
        }
        cin.ignore(2);
        ncase++;
    }
}