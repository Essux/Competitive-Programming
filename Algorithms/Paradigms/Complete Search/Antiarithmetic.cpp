#include <cstdio>
#include <iostream>

using namespace std;

#define MAXN 10000 + 5

int n;
int nums[MAXN];
bool visited[MAXN];

bool isAntiarithmetic(){
    for (int i = 0; i < n-2; i++){
        visited[nums[i]] = true;
        for (int j = i+1; j<n; j++) visited[nums[j]] = false;
        for (int j = i+1; j < n-1; j++){
            int next = nums[j] + nums[j] - nums[i];
            visited[nums[j]] = true;
            if (next >= n or next<0) continue;
            if (!visited[next]) return false;
        }
    }
}

int main(){
    while (scanf("%d", &n) and n){
        char trash; scanf("%c", &trash);
        for (int i = 0; i< n; i++) scanf("%d", nums + i);
        cout << (isAntiarithmetic()? "yes" : "no") << '\n';
        
    }
}