// Codeforces R461 D
#include <bits\stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

struct noise {
    long long s, h;
    string str;
    noise() {s = h = 0; str = "";}
    noise(string _str) : str(_str) {
        s = h = 0;
        for (int i = 0; i < _str.size(); i++) {
            if (_str[i]=='s') s++;
            else h++;
        }
    }

    bool operator < (noise other) const {
        return s * other.h > other.s * h;
    }
};

noise arr[MAXN];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        arr[i] = noise(s);
    }
    sort(arr, arr+n);

    long long ans = 0, s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr[i].str.size(); j++) {
            if (arr[i].str[j]=='s') s++;
            else ans += s;
        }
    }
    cout << ans;
}