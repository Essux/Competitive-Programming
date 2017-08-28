#include <iostream>
#include <string>

using namespace std;

int main(){
    string word;
    cin >> word;

    for (int i = 0; i < word.size()-1; i++) {
        if (word[i] == word[i+1]){
            if (i+2 < word.size() and word[i+2] == word[i]){
                int len = 0;
                for (int j = i+2; j < word.size(); j++) {
                    if (word[j] == word[i]) len++;
                    else break;
                }
                word.erase(i+2, len);
                i -= 1;
                continue;
            }
            if (i+3 < word.size() and word[i+2] == word[i+3]){
                word.erase(i+3, 1);
                i -= 1;
                continue;
            }
        }
    }
    cout << word;
}