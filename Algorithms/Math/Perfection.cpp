#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

string processN(int n){
    int sum = 1;
    for (int i = 2; i < sqrt(n); i++){
        if(n%i == 0){
            sum += i + (n/i);
        }
    }
    if (sum > n) return "ABUNDANT";
    else if (sum < n || n == 1) return "DEFICIENT";
    else return "PERFECT";
}

int main(){
    int n;
    cout << "PERFECTION OUTPUT" << endl;
    cin >> n;
    do{
        cout << right << setw(5) << n << "  " << processN(n) << endl;
        //printf("%5d  %s\n", n, processN(n));
        cin >> n;
    } while(n!=0);
    cout << "END OF OUTPUT"<< endl;

    return 0;
}