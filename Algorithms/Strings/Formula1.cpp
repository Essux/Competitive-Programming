#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

struct Pilot {
    string compName, name;
    int m, s, ms;
    Pilot(string _compName, string _name, int _m, int _s, int _ms) : compName(_compName), name(_name), m(_m), s(_s), ms(_ms) {}
    bool operator< (Pilot other) const {
        if (m != other.m) return m < other.m;
        if (s != other.s) return s < other.s;
        if (ms != other.ms) return ms < other.ms;
        return compName < other.compName;
    }
};

int main() {
    int N;
    while (cin >> N) {
        vector<Pilot> pilots;
        while (N--) {
            string name, rubbish, compName;
            cin >> name;
            compName = name;
            for (int i = 0; i < compName.size(); i++)
                compName[i] = tolower(compName[i]);
            int m, s, ms;
            cin >> rubbish >> m  >> rubbish >> s >> rubbish >> ms >> rubbish;
            pilots.push_back(Pilot(compName, name, m, s, ms));
        }
        sort(pilots.begin(), pilots.end());
        for (int i = 0; i < pilots.size(); i++) {
            if (i%2==0) printf("Row %d\n", i/2+1);
            cout << pilots[i].name <<'\n';
        }
        cout << '\n';
    }
}