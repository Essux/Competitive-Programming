#include <iostream>

using namespace std;

int cycle(unsigned int num){
    int times = 1;
    while (num!=1){
        if (num%2!=0){
            num = 3 * num +1;
        }
        else{
            num = num >> 1;
        }
        times++;
    }
    return times;
}

int main(){
    int a, b;
    while(cin >> a >> b){
        int a1 = a;
        int b1 = b;
        int max = 0;
        if (a > b){
            int temp = a;
            a = b;
            b = temp;
        }
        for(int i = a; i<=b; i++){
            int curr = cycle(i);
            if (curr > max)
                max = curr;
        }
        printf("%d %d %d\n", a1, b1, max);
    }

    return 0;
}