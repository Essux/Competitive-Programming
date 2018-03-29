#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 5000
#define D(_x) cout << #_x":" << _x << endl;

int is_not_on(int _mask, int _i) {return (_mask & (1<<_i))==0;}

int is_on(int mask, int i) {return mask & (1<<i);}

int turn_off(int _mask, int _i) {return _mask & ~(1<<_i);}

int turn_on(int mask, int i) {return mask | (1<<i);}

int memo[MAXN];

void printMask(int k) {
    for (int i = 11; i >= 0; i--) {
        if (k & (1<<i)) printf("o");
        else printf("-");
    }
    printf("\n");
}

int dp(int mask) {
    if (memo[mask] != -1) return memo[mask];
    int minPebbles = 12, pebbles = 0;
    bool moves = false;
    for (int i = 11; i >=0; i--) {
        if (is_on(mask, i)) {
            //printf("Found an o at %d\n", i);
            pebbles++;
            int left = i+2;
            if (left < 12 && is_not_on(mask, left) && is_on(mask, left-1)) {
                int nextMask = turn_off(mask, i);
                nextMask = turn_on(nextMask, left);
                nextMask = turn_off(nextMask, left-1);
                minPebbles = min(minPebbles, dp(nextMask));
                moves = true;
            }
            int right = i-2;
            if (right >= 0 && is_not_on(mask, right) && is_on(mask, right+1)) {
                int nextMask = turn_off(mask, i);
                nextMask = turn_on(nextMask, right);
                nextMask = turn_off(nextMask, right+1);
                minPebbles = min(minPebbles, dp(nextMask));
                moves = true;
            }
        }
    }
    if (moves) return memo[mask] = minPebbles;
    else return memo[mask] = pebbles;
}

int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        string line;
        cin >> line;
        int mask = 0;
        for (int i = 0; i < line.size(); i++) {
            if (line[i]=='o') mask |= 1 << (11-i);
        }
        //printf("%d\n", mask);
        fill(memo, memo+MAXN, -1);
        printf("%d\n", dp(mask));
    }
}