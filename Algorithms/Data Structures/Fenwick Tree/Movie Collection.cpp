#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 100000 + 100000 + 5

int max_size;
int F[MAXN], pos[MAXN>>1];

int rsq(int k){
    int sum = 0;
    for (; k; k -= k & (-k))
        sum += F[k];
    return sum;
}

void adjust(int k, int delta){
    for (; k<max_size; k += k & (-k))    
        F[k] += delta;
}

int main(){
    int cases;
    cin >> cases;
    while (cases--){
        int n, m;
        cin >> n >> m;
        max_size = n+m+1;
        for (int i = 0; i <= max_size; i++) F[i] = 0;
        for (int i = 1; i <= n; i++){
            pos[i] = m+i;
            adjust(pos[i], 1);
        }
        int offset = m;

        while (m--){
            int q; cin >> q;
            int moviesOver = rsq(pos[q]-1);
            cout << moviesOver << (m ? ' ':'\n');
            adjust(pos[q], -1);
            pos[q] = offset--;
            adjust(pos[q], 1);
        }
    }
}