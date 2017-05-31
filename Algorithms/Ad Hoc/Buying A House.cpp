#include <iostream>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    m--;
    int houses[n];
    for (int i = 0; i < n; i++) cin >> houses[i];
    int i;
    for (i = 1; i < n; i++){
        if (m-i>=0 and houses[m-i] and houses[m-i] <= k) break;
        if (m+i<n and  houses[m+i] and houses[m+i] <= k) break;
    }
    cout << i*10;
}