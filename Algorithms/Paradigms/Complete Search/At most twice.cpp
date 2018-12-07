// UVa 13004 - At most twice
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 18 + 2;

int arr[MAXN], cnt[MAXN];

int main() {
    string s;
    while (cin >> s) {
        int n = s.size();
        memset(cnt, 0, sizeof(cnt));
        memset(arr, 0, sizeof(arr));
        for (int j = 0; j < n; j++) arr[j] = s[j]-'0';
        int i = 0;
        while (i < n) {
            if (cnt[arr[i]]>=2) {
                while (arr[i]==0) arr[i--] = 9;
                arr[i]--;
                for (int j = i+1; j < n; j++) arr[j] = 9;
                i = 0;
                memset(cnt, 0, sizeof(cnt));
            }
            else cnt[arr[i++]]++;
        }
        bool firstd = false;
        for (int j = 0; j < n; j++) {
            if (firstd) cout << arr[j];
            else {
                if (arr[j]!=0) {
                    cout << arr[j];
                    firstd = true;
                }
            }
        }
        cout << '\n';
    }
}