#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int n;
    int set = 1;
    while(true){
        cin >> n;
        if (n==0) break;
        int stacks[n];
        int i;
        int moves = 0, mean = 0;
        for (i = 0; i<n; i++){
            cin >> stacks[i];
            mean += stacks[i]; 
        }
        mean /= i;
        for (i = 0; i<n; i++) {
            if (stacks[i]>mean) moves += stacks[i] - mean;
        }
        printf("Set #%d\n", set);
        printf("The minimum number of moves is %d.\n", moves);
        cout << endl;
        set++;
    }

    return 0;
}