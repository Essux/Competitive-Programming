#include <cstdio>
#include <iostream>

using namespace std;

int sumOfDigits(long long n) {
    long long sum = 0;
    while (n != 0) {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

int main() {
    long long N, S;
    cin >> N >> S;
    long long l = 1, r = 1e18 + 1e3;
    while (r - l > 1) {
        long long half = (l + r) / 2;
        if (half - sumOfDigits(half) >= S) r = half;
        else l = half;
    }
    if (r > 1e18) cout << 0;
    else cout << max(0LL, N - r + 1);
}