#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

#define MAXN (int) (5e5 + 10)

int main(){
    int N;
    scanf("%d", &N);
    vector<int> nums;
    for (int i = 0; i< N; i++) {
        int a;
        scanf("%d", &a);
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end(), greater<int>());
    int half = (nums.size()+1)/2;
    vector<int> nums2(nums.begin(), nums.begin() + half);
    vector<int> nums1(nums.begin() + half, nums.end());
    int i = 0, j = 0, res = 0;
    while (i<nums1.size() and nums2.size()){
        if (nums2[j]/2 >= nums1[i]){
            j++;
            i++;
            res++;
        }
        else {
            i++;
            res++;
        }
    }
    printf("%d", res + (nums1.size() - i) + (nums2.size() - j));
}