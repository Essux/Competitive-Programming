#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    while (cin >> n >> m && (n || m)){
        int heads[n], knights[m];
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            heads[i] = x;
        }
        for (int i = 0; i < m; i++){
            int x;
            cin >> x;
            knights[i] = x;
        }
        sort(heads, heads+n);
        sort(knights, knights+m);
        int k, h, money;
        k = h = money = 0;
        while (h < n && k < m){
            while (knights[k] < heads[h] && k < m) {k++;}
            if (k >= m) break;
            money += knights[k];
            k++; h++;
        }
        if (h < n) cout << "Loowater is doomed!\n";
        else cout << money << '\n';
    }
}