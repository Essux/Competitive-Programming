#include <string>
#include <iostream>

using namespace std;

int main(){
    int N; cin >> N;
    string str;
    cin >> str;
    int count = 0;
    for (int i = 0; i < str.size()-1; i++)
        if (str[i] == str[i+1]) count++;
    cout << count;
}