// Solution to UVa - 297 Quadtrees
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const int size = 1024;
const int MAXN = size + 5;

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

string S;

int parse(int depth, int pos, int child, int bias) {
    if (S[pos]=='f') {
        int l = (size/pow(4, depth)) * child + bias;
        int r = l + (size/pow(4, depth));
        adjust(l+1, 1);
        adjust(r+1, -1);
    }
    else if (S[pos]=='p') {
        int nextPos = 0, curchild = -1;
        for (int i = 0; i < 4; i++) {
            nextPos++; curchild++;
            nextPos += parse(depth + 1, pos + nextPos, curchild, (size/pow(4, depth)) * child + bias);
        }
        return nextPos;
    }
    return 0;
}

int main() {
    int n; scanf("%d", &n);
    while (n--) {
        fill(F, F+MAXN, 0);
        cin >> S;
        parse(0, 0, 0, 0);
        cin >> S;
        parse(0, 0, 0, 0);
        int sum = 0;
        for (int i = 1; i <= 1024; i++) {
            int a = rsq(i);
            if (a>=1) sum++;
        }
        printf("There are %d black pixels.\n", sum);
    }
}