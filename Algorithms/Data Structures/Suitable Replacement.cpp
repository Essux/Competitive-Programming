#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define Dv(_x) cout << #_x":" << _x << endl;

int origN[28], searchN[28], curN[28];

int main() {
    string orig;
    cin >> orig;
    fill(origN, origN + 28, 0);
    fill(searchN, searchN + 28, 0);
    fill(curN, curN + 28, 0);
    int wild = 0;
    for (int i = 0; i < orig.size(); i++) {
        if (orig[i] == '?') wild++;
        else origN[orig[i] - 'a']++;
    }

    string search;
    cin >> search;
    for (int i = 0; i < search.size(); i++)
        searchN[search[i] - 'a']++;

    int j = 0;
    for (int i = 0; i < orig.size(); i++) {
        if (orig[i] != '?') continue;
        while (true) {
            if (j >= 26) fill(curN, curN + 28, 0);
            char c = 'a' + j;
            if (searchN[j] > curN[j]) {
                if (origN[j]>0) {
                    curN[j]++;
                    origN[j]--;
                }
                else {
                    orig[i] = 'a' + j;
                    curN[j]++;
                    break;
                }
            }
            else {
                if (j>=26) j=0;
                else j++;
            }
        }
    }

    cout << orig;
}