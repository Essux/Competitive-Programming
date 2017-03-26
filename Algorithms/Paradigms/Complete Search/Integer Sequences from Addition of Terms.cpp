#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    int C;
    cin >> C;
    while (C--){
        int i;
        cin >> i;
        i++;
        int poly[i];
        for (int m = 0; m < i; m++){
            int j;
            cin >> j;
            poly[m] = j;
        }
        int d, k;
        cin >> d >> k;

        int n = 1, rep = 0;
        for (int m = 0; m < k; m++){
            if (rep < n*d) rep++;
            else {n++; rep = 1;}
        }

        long bn = 0;
        for (int m = 0; m < i; m++){
            bn += poly[m]*pow(n, m);
        }

        cout << bn << endl;
    }
}