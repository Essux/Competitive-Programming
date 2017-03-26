#include <string>
#include <iostream>
#include <cctype>
#include <cstdio>

using namespace std;

int main(){
    string line;
    while (cin >> line){
        long zero, one, two;
        zero = one = two = 0;
        long subs = 0, a = 0;
        for (int i = 0; i < line.size(); i++){
            if (isalpha(line[i])) zero = one = two = a = 0;
            else {
                int d = (line[i] - 48) % 3;
                a = (d + a) % 3;
                if (a==0) {subs++; subs += zero; zero++;}
                else if (a==1) {subs += one; one++;}
                else {subs += two; two++;}
            }
        }
        cout << subs << '\n';
    }
}