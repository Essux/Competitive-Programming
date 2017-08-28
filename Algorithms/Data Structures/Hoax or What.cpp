#include <cstdio>
#include <set>
#include <iostream>

using namespace std;

int main() {
    int N;
    while (scanf("%d", &N) and N!=0) {
        long long sum = 0;
        multiset<int> nums;
        while (N--) {
            int k;
            scanf("%d", &k);
            while (k--) {
                int a;
                scanf("%d", &a);
                nums.insert(a);
            }
            multiset<int>::iterator min = nums.begin();
            multiset<int>::iterator max = nums.end();
            sum += *(--max) - *min;
            nums.erase(min);
            nums.erase(max);
        }
        cout << sum << '\n';
    }
}