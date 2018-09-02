// SPOJ Fibonacci Sum - FIBOSUM
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MSZ = 3;

struct Matrix {ll mat[MSZ][MSZ];};

Matrix qmat, baseC;
ll _qmat[3][3] = {
        {1, 1, 0},
        {0, 1, 1},
        {0, 1, 0}
};
ll _baseC[3][3] = {
        {0, 0, 0},
        {1, 0, 0},
        {0, 0, 0}
};
ll MOD = 1e9 + 7;

Matrix matMul (Matrix a, Matrix b) {
    Matrix ans; int i, j, k;
    for (i = 0; i < MSZ; i++)
        for (j = 0; j < MSZ; j++)
            for (ans.mat[i][j] = k = 0; k < MSZ; k++) {
                ans.mat[i][j] += (a.mat[i][k]%MOD) * (b.mat[k][j]%MOD);
                ans.mat[i][j] %= MOD;
                ans.mat[i][j] += MOD;
                ans.mat[i][j] %= MOD;
            }

    return ans;
}

Matrix matPow (Matrix base, int p) {
    Matrix ans; int i, j;
    for (i = 0; i < MSZ; i++)
        for (j = 0; j < MSZ; j++) ans.mat[i][j] = (i==j);
    while (p) {
        if (p&1) ans = matMul(ans, base);
        base = matMul(base, base);
        p>>=1;
    }
    return ans;
}

ll fiboSum (int b) {
    if (b<=0) return 0;
    Matrix ans = matMul(matPow(qmat, b), baseC);
    return ans.mat[0][0];
}

int main() {
    for (int i = 0; i < MSZ; i++)
         for (int j = 0; j < MSZ; j++)
            qmat.mat[i][j] = _qmat[i][j],
            baseC.mat[i][j] = _baseC[i][j];

    int t; scanf("%d", &t);
    while (t--) {
        int a, b; scanf("%d %d", &a, &b);
        ll ansA = fiboSum(a-1);
        ll ansB = fiboSum(b);
        ll ans = (ansB - ansA + MOD)%MOD;
        printf("%lld\n", ans);
    }
}