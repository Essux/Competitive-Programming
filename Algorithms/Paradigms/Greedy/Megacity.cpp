#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<int, int> dist_pop;

#define MILLION 1000000

int main(){
    int N, S;
    scanf("%d %d", &N, &S);
    vector<dist_pop> cities;
    while(N--){
        int x, y, k;
        scanf("%d %d %d", &x, &y, &k);
        cities.push_back(dist_pop(x*x + y*y, k));
    }
    sort(cities.begin(), cities.end());
    int sum = S, i = 0;
    for (; i<cities.size() and sum < MILLION; i++)
        sum += cities[i].second;
    if (sum < MILLION) printf("-1");
    else printf("%.9f", sqrt(cities[i-1].first) );
}