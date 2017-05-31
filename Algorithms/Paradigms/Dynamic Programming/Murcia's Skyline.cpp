#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 3000 + 5

int h[MAXN], w[MAXN], lisMemo[MAXN], ldsMemo[MAXN];
int N;

int lis(int index){
    if (index == 0) return w[index];
    if (lisMemo[index] != -1) return lisMemo[index];
    int cand = 0;
    for (int i = 0; i < index; i++){
        //printf("h[i] < h[index] %d vs %d\n", h[i], h[index]);
        if (h[i] < h[index]) cand = max(cand, lis(i));
    }
    //printf("LIS %d = %d\n", index, cand+ w[index]);
    return lisMemo[index] = cand + w[index];
}

int lds(int index){
    if (index == 0) return w[index];
    if (ldsMemo[index] != -1) return ldsMemo[index];
    int cand = 0;
    for (int i = 0; i < index; i++){
        if (h[i] > h[index]) cand = max(cand, lds(i));
    }
    return ldsMemo[index] = cand + w[index];
}

int main(){
    int T; cin >> T;
    for (int ncase = 1; ncase <= T; ncase++){
        cin >> N;
        for (int i = 0; i< N; i++) scanf("%d", h+i);
        for (int i = 0; i< N; i++) scanf("%d", w+i);
        fill(lisMemo, lisMemo+N, -1);
        fill(ldsMemo, ldsMemo+N, -1);
        int inc = 0;
        for (int i = 0; i< N; i++) inc = max(inc, lis(i));
        int dec = 0;
        for (int i = 0; i< N; i++) dec = max(dec, lds(i));  
        printf("Case %d. ", ncase);
        if (inc >= dec){
            printf("Increasing (%d). ", inc);
            printf("Decreasing (%d).", dec); 
        }
        else {
            printf("Decreasing (%d). ", dec); 
            printf("Increasing (%d).", inc);
        }
        printf("\n");
    }
}