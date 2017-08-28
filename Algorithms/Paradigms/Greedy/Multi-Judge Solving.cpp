#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> nums;
    while (n--) {
        int a;
        scanf("%d", &a);
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());
    n = nums.size();
    int i = 0, other = 0;
    while (i < n) {
        if (nums[i] <= k*2) {
            k = max(nums[i], k);
            i++;
        }
        else {
            k = k*2;
            other++;
        }
    }
    printf("%d", other);
}