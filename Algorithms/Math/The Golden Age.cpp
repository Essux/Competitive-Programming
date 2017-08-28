#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long x, y, l, r;
    cin >> x >> y >> l >> r;
    vector<long long> nums;
    long long num1 = 1;


    long long num2 = 1;
    nums.push_back(num1 + num2);
    while (num2 <= r / y){
        num2 *= y;
        nums.push_back(num1 + num2);
    }

    while (num1 <= r / x){
        num1 *= x;
        long long num2 = 1;
        nums.push_back(num1 + num2);
        while (num2 <= r / y){
            num2 *= y;
            nums.push_back(num1 + num2);
        }
    }
    sort(nums.begin(), nums.end());
    long long maxLen = 0, prev = l-1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < l) continue;
        if (nums[i] > r) break;
        if (nums[i] == r) {
            maxLen = max(maxLen, r - prev - 1);
            prev = r;
            break;
        }
        maxLen = max(maxLen, nums[i] - prev - 1);
        prev = nums[i];
    }
    maxLen = max(maxLen, r - prev);

    cout << maxLen;
}