#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, c, s;
    while (cin >> n >> c >> s) {
        int count = 1, times = 0;
        if (count==s) times++;
        while (c--) {
            int a; cin >> a;
            if (a==1) count = (count==n)? 1: count+1;
            else count = (count==1)? n:count-1;
            if (count==s) times++;
        }
        printf("%d\n", times);
    }
}