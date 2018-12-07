// UVa 441 - Lotto
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 13 + 4;

int k;
int arr[MAXN];
vector<int> sel;

void back(int id, int cur) {
    if (cur==6) {
        cout << sel[0];
        for (int i = 1; i < 6; i++) cout << ' ' << sel[i];
        cout << '\n';
        return;
    }
    if (id>=k) return;
    sel.push_back(arr[id]);
    back(id+1, cur+1);
    sel.pop_back();
    back(id+1, cur);
}

int main() {
    int ncase = 0;
    while (cin >> k && k) {
        for (int i = 0; i < k; i++) cin >> arr[i];
        if (ncase++>0) cout << '\n';
        back(0, 0);
    }
}