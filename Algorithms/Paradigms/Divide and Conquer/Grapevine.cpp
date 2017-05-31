#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define Darr(x, l) //for (int jj = 0; jj < l; jj++) cout << x[jj] << " "; cout << '\n';
#define D(x_) //cout << #x_":" << x_ << '\n';

#define MAXN 500 + 4

vector< vector<int> > matij;
vector< vector<int> > matji;

int main(){
    int r, c;
    while (cin >> r >> c and r){
        matij = vector< vector<int> >(MAXN, vector<int>(MAXN, 0));
        matji = vector< vector<int> >(MAXN, vector<int>(MAXN, 0));   
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                int h; cin >> h;
                matij[i][j] = h;
                matji[j][i] = h;
            }
        }
        int n; cin >> n;
        while (n--){
            int minN, maxN; cin >> minN >> maxN;
            int maxX = upper_bound(matij[0].begin(), matij[0].begin()+c, maxN)-matij[0].begin()-1;
            maxX = maxX <= 0 ? 0:maxX;
            D(maxX);
            int maxDistance = -1;
            for (int i = 0; i <= maxX; i++){
                vector<int>::iterator lowBoundI = lower_bound(matji[i].begin(), matji[i].begin()+r, minN);
                int lowBound = lowBoundI-matji[i].begin();
                int minY = lowBound;
                
                vector<int>::iterator upBoundI = upper_bound(matji[i].begin(), matji[i].begin()+r, maxN);
                int upBound = upBoundI-matji[i].begin()-1;
                int maxY = min(c-i-1+lowBound, upBound);

                bool found =false;
                for (int j = maxY; maxY>=minY && !found; j--){
                    D(matji[i+j-minY][j]);
                    if (matji[i+j-minY][j]<=maxN) {
                        found = true;
                        if (maxDistance < j-minY) maxDistance = j-minY;
                    }
                }
            }
            cout << maxDistance+1 << '\n';
        }
        cout << "-\n";
    }
}