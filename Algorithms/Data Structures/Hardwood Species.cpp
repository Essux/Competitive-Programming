#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> trees;
map<string, int>::iterator it;

int processTrees(){
    string word;
    int count = 0;
    while(getline(cin, word) and word != ""){
        count++;
        if (trees.count(word) == 0){
            trees[word] = 1;
        }
        else{
            trees[word]++;
        }
    }
    return count;
}

int main(){
    int times;
    cin >> times;
    string jump;
    getline(cin, jump);
    getline(cin, jump);
    while(times--){
        int totalTrees = processTrees();
        for(it = trees.begin(); it!=trees.end(); it++){
            float freq = 100 * (float)it->second / (float)totalTrees;
            printf("%s %.4f\n", it->first.c_str(), freq);
        }
        trees.clear();
        if (times != 0) cout << endl;
    }
}