#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    while (scanf("%d", &N) and N) {
        string st;
        cin >> st;
        int minD = 1 <<30;
        int lastR = -1, lastD = -1;
        for (int i = 0; i < st.size(); i++) {
            if (st[i] == 'R') {
                if (lastD != -1) minD = min(minD, i - lastD);
                lastR = i;
            }
            else if (st[i] == 'D') {
                if (lastR != -1) minD = min(minD, i - lastR);
                lastD = i;
            }
            else if (st[i] == 'Z') {
                minD = 0;
            }
        }
        printf("%d\n", minD);
    }
}