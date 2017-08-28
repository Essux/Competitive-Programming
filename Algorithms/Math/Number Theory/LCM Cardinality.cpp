#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

#define D(_x) //cout << _x << " ";

vector<int> divisors;

int gcd(int a, int b) {return b==0 ? a : gcd(b, a%b);}

int lcm(int a, int b) {return a * (b / gcd(a, b));}

void getDivisors(int n) {
    for (int i = 1; i*i <= n; i++)
        if (n % i == 0) {
            divisors.push_back(i);
            if (n/i != i) divisors.push_back(n/i);
        }
}

int main() {
    int N;
    while (scanf("%d", &N) != EOF and N != 0) {
        divisors.clear();
        int cardinality = 0;
        getDivisors(N);
        for (int i = 0; i < divisors.size(); i++)
            for (int j = i; j < divisors.size(); j++)
                if (lcm(divisors[i], divisors[j]) == N) cardinality++;
        printf("%d %d\n", N, cardinality);
    }
}