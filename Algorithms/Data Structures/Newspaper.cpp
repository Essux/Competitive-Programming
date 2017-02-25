#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int k;
        unsigned long long cents = 0;
        cin >> k;
        int values[256];
        for (int i = 0; i<256; i++) values[i] = 0;
        while (k--){
            char c;
            int value;
            cin >> c >> value;
            values[c] = value;
        }
        int m;
        cin >> m;
        string line;
        getline(cin, line);
        while(m--){
            char curChar;
            while ((curChar = cin.get()) != '\n'){
                cents += values[curChar];
            }
        }
        printf("%.2f$\n", cents / 100.0);
    }
}