#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    bool holes[n];
    for (int i = 0; i <n; i++) holes[i] = false;
    for (int i = 0; i < m; i++){int p; scanf("%d", &p); holes[--p] = true;}
    int bone = 0;
    if (!holes[0]){
        while (k--){
            int u, v;
            scanf("%d %d", &u, &v);
            u--; v--;
            if (u==bone){
                bone = v;
                if (holes[bone]) break;
            }
            else if (v == bone){
                bone = u;
                if (holes[bone]) break;
            }
        }
    }
    printf("%d", bone+1);
}