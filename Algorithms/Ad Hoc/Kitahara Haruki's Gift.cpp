// Codeforces Round #248 (Div. 2) - A
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 5;

int arr[MAXN];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n, greater<int>());
    int ac = 0;
    for (int i = 0; i < n; i++) {
        if (ac>0) ac -= arr[i];
        else ac += arr[i];
    }
    cout << (ac==0 ? "YES" : "NO") << endl;
}