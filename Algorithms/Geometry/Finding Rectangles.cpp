#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 52

typedef pair<int, int> point;

int matrix[MAXN][MAXN];
map<point, char> points_map;
vector<string> rectangles;

void auxfind(vector<point> curPoints){
    point prevPoint;
    switch(curPoints.size()){
        case 1:
            prevPoint = curPoints[0];            
            for (int i = prevPoint.first+1; i < MAXN; i++){
                if (matrix[i][prevPoint.second]) {
                    vector<point> temp1(curPoints);
                    temp1.push_back(point(i, prevPoint.second));
                    auxfind(temp1);
                }
            }
            break;
        case 2:
            prevPoint = curPoints[1];
            for (int i = prevPoint.second-1; i>=0; i--){
                if (matrix[prevPoint.first][i]){
                    vector<point> temp1(curPoints);
                    temp1.push_back(point(prevPoint.first, i));
                    auxfind(temp1);
                }
            }
            break;
        case 3:
            int x, y;
            x = curPoints[0].first;
            y = curPoints[2].second;

            if (matrix[x][y]) {
                //printf("      Check 4: %d, %d\n", x, y);
                curPoints.push_back(point(x, y));
                string str = "";
                for (int i = 0; i < curPoints.size(); i++){
                    str += points_map.find(curPoints[i])->second;
                }
                rectangles.push_back(str);
            }
    }
}

void findRectangles(){
    for (int j = 0; j < MAXN; j++){
        for (int i = 0; i < MAXN; i++){
            if (matrix[i][j]) {
                vector<point> empty;
                empty.push_back(point(i, j));
                //printf("Check 1: %d, %d\n", i, j);
                auxfind(empty);
            }
        }
    }
}

int main(){
    int n, ncase = 0;
    while (cin >> n && n){
        for (int i = 0; i < MAXN; i++){
            for (int j = 0; j < MAXN; j++){
                matrix[i][j] = 0;
            }
        }
        points_map.clear();
        rectangles.clear();
        while (n--){
            char c;
            int x, y;
            cin >> c >> x >> y;
            points_map[point(x, y)] = c;
            matrix[x][y] = 1;
        }
        findRectangles();
        
        printf("Point set %d:", ++ncase);
        if (rectangles.size()==0) printf(" No rectangles");
        else {
            printf("\n");
            sort(rectangles.begin(), rectangles.end());
            for(int i = 0; i < rectangles.size(); i++) {
                cout << " " << rectangles[i];
                if ((i+1) % 10 == 0 && rectangles.size()-1 > i) printf("\n");
            }
        }
        printf("\n");
    }
}