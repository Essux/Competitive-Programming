#include <iostream>
#include <string>

using namespace std;

int main(){
    string line;
    bool isOpen = false;
    while(true){
        getline(cin, line);
        if (!cin) break;
        string result = "";
        for (string::iterator it = line.begin(); it!=line.end(); it++){
            if (*it == '"'){
                if (isOpen) {
                    result += "''";
                    isOpen = false;
                }
                else {
                    result +="``";
                    isOpen = true;
                }
            }
            else result += *it;
        }
        cout << result << endl;
    }

    return 0;
}