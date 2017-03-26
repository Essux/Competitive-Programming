#include <iostream>
#include <bitset>

using namespace std;

#define MILLION 1000000

bitset<MILLION> schedule;

bool fits_one_time_task(int s, int f){
    while (s < f && s < MILLION){
        if (!schedule[s]) schedule[s] = 1;
        else return false;
        s++;
    }
    return true;
}

bool fits_repeating_task(int s, int f, int r){
    while (s<MILLION){
        if (!fits_one_time_task(s, f)) return false; 
        s+=r; f+=r;
    }
    return true;
}

int main(){
    int one_time, repeating;
    while (cin >> one_time >> repeating && (one_time != 0 || repeating != 0)){
        schedule.reset();
        bool conflict = false;
        while (one_time--){
            int s, f;
            cin >> s >> f;
            if (!conflict && !fits_one_time_task(s, f)) conflict = true;
        }
        while (repeating--){
            int s, f, r;
            cin >> s >> f >> r;
            if (!conflict && !fits_repeating_task(s, f, r)) conflict = true;
        }
        cout << (conflict ? "CONFLICT":"NO CONFLICT") << endl;
    }
}