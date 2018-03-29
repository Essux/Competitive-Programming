#include <bitset>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

#define D(_x) cout << #_x":" << _x << endl;

bitset<9*60> bs;

int main() {
    int N, day = 1;
    while (cin >> N) {
        bs.reset();
        while (N--) {
            int fromH, fromM, fromTime, toH, toM, toTime;
            scanf("%d:%d", &fromH, &fromM);
            scanf("%d:%d", &toH, &toM);
            string rubbish; getline(cin, rubbish);
            fromTime = fromH * 60 + fromM;
            toTime = toH * 60 + toM;
            fromTime -= 10*60;
            toTime -= 10*60;
            for (int i = fromTime; i < toTime; i++) bs.set(i);
        }

        bool inNap = false;
        int maxNap = 0, curNap = 0, maxStart = -1, curStart = -1;
        for (int i = 0; i < 60*8; i++) {
            if (inNap) {
                if (bs[i]) {
                    inNap = false;
                    if (curNap > maxNap) {
                        maxNap = curNap;
                        maxStart = curStart;
                    }
                }
                else curNap++;
            }
            else
                if (!bs[i]) {
                    curStart = i;
                    curNap = 1;
                    inNap = true;
                }
        }
        if (curNap > maxNap) {
            maxNap = curNap;
            maxStart = curStart;
        }

        maxStart += 10*60;
        printf("Day #%d: the longest nap starts at %d:%02d and will last for ", day++, maxStart/60, maxStart%60);
        if (maxNap >= 60) printf("%d hours and %d minutes.\n", maxNap/60, maxNap%60);
        else printf("%d minutes.\n", maxNap);
    }
}