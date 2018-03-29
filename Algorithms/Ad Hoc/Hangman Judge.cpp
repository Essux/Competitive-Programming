#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int r;
    while (cin >> r && r != -1) {
        string word, guess;
        cin >> word >> guess;
        bool in[26]; fill(in, in+26, false);
        int letters = 0;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (!in[c-'a']) {
                in[c-'a'] = true;
                letters++;
            }
        }

        bool guessed[26]; fill(guessed, guessed+26, false);
        int strokes = 0; char res = 'c';
        for (int i = 0; i < guess.size(); i++) {
            char c = guess[i];
            if (in[c-'a'] && !guessed[c-'a']) letters--;
            if (!in[c-'a'] && !guessed[c-'a']) strokes++;
            guessed[c-'a'] = true;
            if (strokes >= 7) {res = 'l'; break;}
            else if (letters<=0) {res = 'w'; break;}
        }
        printf("Round %d\n", r);
        switch (res) {
            case 'c': printf("You chickened out.\n"); break;
            case 'l': printf("You lose.\n"); break;
            case 'w': printf("You win.\n"); break;
        }
    }
}