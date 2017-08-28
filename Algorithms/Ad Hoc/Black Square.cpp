#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int a[4];
    for (int i = 0; i < 4; i++) scanf("%d", a+ i);
    string str; cin >> str;
    long long sum = 0;
    for (int i = 0; i < str.size(); i++) {
        sum += a[str[i] - '1'];
    }
    cout << sum;
}