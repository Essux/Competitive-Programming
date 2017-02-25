#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    unsigned int n;
    vector<unsigned int> nums;
    while (scanf("%d", &n) != EOF){
        nums.push_back(n);
        sort(nums.begin(), nums.end());
        int middle = nums.size()/2; //Truncated towards 0
        if (nums.size()%2 == 1) printf("%d\n", nums[middle]);
        else {         
            printf("%d\n", (nums[middle-1] + nums[middle]) / 2);
        }
    }
}