#include <cstdio>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int checkLetters(string letters, map<char, bool> let_map){
    int let_count = 0;
    letters.erase(letters.end()-1);
    for (string::iterator it = letters.begin(); it != letters.end(); it++){
        //printf("Current char: %c\n", *it);
        if (let_map.count(*it)) {
            let_map[*it] = true;
            //printf("I have just changed this. Worked? %d\n", let_map.find(*it)->second);
            bool finished = true;
            for (map<char, bool>::iterator it = let_map.begin(); it != let_map.end(); it++){
                //printf("Char %c is %d\n", it->first, it->second);
                finished &= it->second;
            }
            if (finished) return 1; //Win
        }
        else {
            let_count++;
        }
        if (let_count >= 7) return 2;
    }
    return 3; //Chickened out
}

int main(){
    int r;
    while (true){
        scanf("%d", &r);
        if (r == -1) break;
        string word, letters;
        map<char, bool> let_map;
        getline(cin, word);
        getline(cin, word);
        word.erase(word.end()-1);
        getline(cin, letters); 
        /*Deleting repeated letters
        string temp_letters = letters;
        letters.clear();
        bool already[256];
        for (int i = 0; i < 256; i++) already[i] = false; 
        for (int i = 0; i<temp_letters.length(); i++){
            char curchar = temp_letters[i];
            if (!already[curchar]){
                letters.push_back(curchar);
                already[curchar] = true;
            }
        }
        /*   */
        printf("Round %d\n", r);
        for (string::iterator it = word.begin(); it != word.end(); it++)
            let_map[*it] = false;
        switch (checkLetters(letters, let_map)){
            case 1:
                printf("You win.");
                break;
            case 2:
                printf("You lose.");
                break;
            case 3:
                printf("You chickened out.");
        }
        cout << endl;
    }
}