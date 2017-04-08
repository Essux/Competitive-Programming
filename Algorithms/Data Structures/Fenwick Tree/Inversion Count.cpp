#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

#define MAXN 10000003

class FenwickTree {
    private: vector<int> ft;
    public:
        FenwickTree(int n) {ft.assign(n+1, 0);}
        int rsq(int b){
            int sum = 0;
            for (; b; b -= b & (-b)) sum += ft[b];
            return sum;
        }
        void adjust(int k, int v){
            for (; k < (int) ft.size(); k += k & (-k)) ft[k] += v;
        }
};

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int arr[n], temp, max=1;
        for (int i = 0; i < n; i++){
            cin >> temp;
            arr[i] = temp;
            if (temp > max) max = temp;
        }
        
        FenwickTree ft(max);
        long long inv = 0;
        for (int i = n-1; i >= 0; i--){
            inv += ft.rsq(arr[i]-1);
            ft.adjust(arr[i], 1);
        }
        cout << inv << endl;
    }
}