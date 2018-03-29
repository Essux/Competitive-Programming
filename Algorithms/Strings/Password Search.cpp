#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main() {
    int N;
    string word;
    while (cin >> N >> word) {
        map<string, int> times;
        for (int i = 0; i <= word.size()-N; i++) {
            string subs = word.substr(i, N);
            times[subs]++;
            //cout << subs << ' ' << times[subs] << '\n';
        }
        int maxTimes = 0;
        string ans;
        for (map<string, int>::iterator it = times.begin(); it!=times.end(); it++) {
            if (it->second > maxTimes) {
                maxTimes = it->second;
                ans = it->first;
            }
        }
        cout << ans << '\n';
    }
}