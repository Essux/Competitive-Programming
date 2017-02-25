#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

bool sortable(queue<int> out, int n){
    queue<int> in;
    for (int i = 1; i<=n; i++) in.push(i);
    stack<int> mid;
    while (!out.empty()){
        if (in.empty()) return false;
        else {
            mid.push(in.front());
            in.pop();
        }
        while (!mid.empty() && mid.top() == out.front()){
            mid.pop();
            out.pop();
        }
    }
    return true;
}

int main(){
    while (true){
        int n;
        scanf("%d", &n);        
        if (n==0) break;
        while (true){
            int arr1;
            scanf("%d", &arr1);
            if (arr1 == 0) break;
            queue<int> out;
            if (arr1 != 0){
                out.push(arr1);
                for (int i = 0; i<n-1; i++){
                    int arri;
                    scanf("%d", &arri);
                    out.push(arri);
                }
                if (sortable(out, n)) printf("Yes\n");
                else printf("No\n");
            }
        }
        printf("\n");
    }
}