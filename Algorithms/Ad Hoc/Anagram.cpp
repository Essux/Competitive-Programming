#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool my_comp(char c1, char c2){
    if (tolower(c1) != tolower(c2)) return tolower(c1) < tolower(c2);
    else return (int) c1 < (int) c2;
}

int main(){
    int n;
    cin >> n;
    while (n--){
        string word;
        cin >> word;
        sort(word.begin(), word.end(), my_comp);
        do {
            cout << word << endl;
        } while (next_permutation(word.begin(), word.end(), my_comp));
    }
}