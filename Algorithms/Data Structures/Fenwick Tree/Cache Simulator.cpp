#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

#define MAXN 10000000 + 5
#define MAXPOS 16777216 + 5

int F[MAXN];
int pos[MAXPOS];
int cacheSizes[30], cacheMisses[30];
int curPos = MAXN-4;
int caches;

int rsq(int k){
    int sum = 0;
    for (; k; k-= k & (-k)) sum += F[k];
    return sum;
}

void adjust(int k, int delta){
    for (; k<MAXN; k+= k & (-k)) F[k] = F[k] + delta;
}

void ADDR(int n){
    if (pos[n] == 0){
        pos[n] = curPos;
        adjust(curPos, 1);
        curPos--;
        for (int i = 0; i < caches; i++) cacheMisses[i]++;
    }
    else {
        int p = rsq(pos[n]);
        for (int i = 0; i < caches; i++) if (cacheSizes[i]<p) cacheMisses[i]++;
        adjust(pos[n], -1);
        pos[n] = curPos;
        adjust(curPos, 1);
        curPos--; 
    }
}

int main(){
    scanf("%d", &caches);
    for (int i = 0; i < caches; i++) scanf("%d",&cacheSizes[i]);
    memset(cacheMisses, 0, sizeof cacheMisses);
    memset(F, 0, sizeof F);
    memset(pos, 0, sizeof pos);

    string command;
    while (cin >> command and command != "END"){
        if (command == "ADDR"){
            int n;
            scanf("%d", &n);
            ADDR(n);
        }
        else if (command == "STAT"){
            for (int i = 0; i < caches; i++) printf("%d%c",cacheMisses[i], (i!=caches-1? ' ':'\n'));            
            memset(cacheMisses, 0, sizeof cacheMisses);            
        }
        else {
            int b, y, n;
            scanf("%d %d %d", &b, &y, &n);
            for (int k = 0; k<n; k++) ADDR(b+y*k);
        }
    }
}