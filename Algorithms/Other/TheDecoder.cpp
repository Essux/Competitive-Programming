#include <iostream>
#include <string>

using namespace std;

int main(){
    string line;
    while(cin >> line){
        for (string::iterator it = line.begin(); it != line.end(); it++){
            *it -= 7;
        }
        cout << line << endl;
    }
    return 0;
}