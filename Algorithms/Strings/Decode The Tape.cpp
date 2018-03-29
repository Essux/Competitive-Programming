#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int pow(int b, int e) {
    int ans = 1;
    while (e--) ans *= b;
    return ans;
}

int main() {
    string line;
    getline(cin, line);
    while (true) {
        getline(cin, line);
        //cout << line;
        if (line.find("___________")!=-1) break;
        int pot = 6;
        char c = 0;
        for (int i = 2; i < 10; i++) {
            //cout << line[i];
            if (line[i]==' ') pot--;
            if (line[i] == 'o') {
                c += pow(2, pot);
                pot--;
            }
        }
        printf("%c", c);
    }
}