#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int n, x, q, m;
    cin >> n;
    vector<int> prices(n,0); 
    
    for(int i = 0; i < n; i++) {
        cin >> x;
        prices[i] = x;
    }
    sort(prices.begin(), prices.end());
    vector<int>::iterator low;
    cin >> q;
    while(q--) {
        cin >> m;
        low = lower_bound(prices.begin(), prices.end(), m+1);
        cout << low - prices.begin() << endl;
    }


    return 0;
}