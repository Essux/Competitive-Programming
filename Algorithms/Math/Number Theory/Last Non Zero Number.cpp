#include <iostream>
#include <cstdio>
using namespace std;

long long p(long long n, long long m) {
	long long x = 1;
	for (long long i = n-m+1; i <= n; i++) {
		x *= i;
		while (x % 10 == 0) x /= 10;
		x %= 100000000000;
	}
	return x;
}

int main() {
	long long N, M;
	while (scanf("%lld %lld", &N, &M) != EOF) {
		printf("%lld\n", p(N, M) % 10);
	}
}