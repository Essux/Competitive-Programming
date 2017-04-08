#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

#define INFINITY 1<<6

int main(){
    int n;
    cin >> n;
    while (n--){
        int r, c;
        char actual_char;
        cin >> r >> c;
        cin.ignore(2);
        int walls[r][c];
        vector<pair<int, int> > fires;
        pair<int, int> joe;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                cin.get(actual_char);
                switch(actual_char){
                    case '#':
                        walls[i][j] = 1;
                        break;
                    case 'J':
                        joe = make_pair(i, j);
                        //printf("Found Joe at %d, %d\n", i, j);
                        walls[i][j] = 0;
                        break;
                    case 'F':
                        //printf("Found Fire at %d, %d\n", i, j);                    
                        fires.push_back(make_pair(i, j));
                        walls[i][j] = 0;
                        break;
                    case '.':
                        walls[i][j] = 0;
                        break;
                }
            }
            cin.ignore(2);
        }
        /* Traversing the maze */
        int fireM[r][c], joeM[r][c];
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                joeM[i][j] = INFINITY;
            }
        }
        queue<pair<int, int> > joeQueue;
        joeQueue.push(joe);
        joeM[joe.first][joe.second] = 0;
        while(!joeQueue.empty()){
            pair<int, int> curJoePos = joeQueue.front();
            joeQueue.pop();
            //if (joeM[curJoePos.first][curJoePos.second] == 6) printf("Weird Position: ");
            //printf("Joe is in %d, %d in %d minutes\n", curJoePos.first, curJoePos.second, joeM[curJoePos.first][curJoePos.second]);

            if (curJoePos.first > 0 && walls[curJoePos.first-1][curJoePos.second] == 0 && joeM[curJoePos.first-1][curJoePos.second] == INFINITY) {
                joeQueue.push(make_pair(curJoePos.first-1, curJoePos.second));
                joeM[curJoePos.first-1][curJoePos.second] = joeM[curJoePos.first][curJoePos.second]+1;
            }
            if (curJoePos.first < r && walls[curJoePos.first+1][curJoePos.second] == 0 && joeM[curJoePos.first+1][curJoePos.second] == INFINITY) {
                joeQueue.push(make_pair(curJoePos.first+1, curJoePos.second));
                joeM[curJoePos.first+1][curJoePos.second] = joeM[curJoePos.first][curJoePos.second]+1;
            }                
            if (curJoePos.second > 0 && walls[curJoePos.first][curJoePos.second-1] == 0 && joeM[curJoePos.first][curJoePos.second-1] == INFINITY) {
                joeQueue.push(make_pair(curJoePos.first, curJoePos.second-1)); 
                joeM[curJoePos.first][curJoePos.second-1] = joeM[curJoePos.first][curJoePos.second]+1;            
            }
            if (curJoePos.second < c && walls[curJoePos.first][curJoePos.second+1] == 0 && joeM[curJoePos.first][curJoePos.second+1] == INFINITY) {
                joeQueue.push(make_pair(curJoePos.first, curJoePos.second+1));
                joeM[curJoePos.first][curJoePos.second+1] = joeM[curJoePos.first][curJoePos.second]+1;              
            }
        }
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                fireM[i][j] = INFINITY;
            }
        }
        queue<pair<int, int> > fireQueue;
        for (int i  = 0; i < fires.size(); i++) {
            fireQueue.push(fires[i]);
            fireM[fires[i].first][fires[i].second] = 0;
        }
        while (!fireQueue.empty()){
            pair<int, int> curFirePos = fireQueue.front();
            fireQueue.pop();

            if (curFirePos.first >= 0 && walls[curFirePos.first-1][curFirePos.second] == 0 && fireM[curFirePos.first-1][curFirePos.second] == INFINITY) {
                fireQueue.push(make_pair(curFirePos.first-1, curFirePos.second));
                fireM[curFirePos.first-1][curFirePos.second] = fireM[curFirePos.first][curFirePos.second]+1;
            }
            if (curFirePos.first < r && walls[curFirePos.first+1][curFirePos.second] == 0 && fireM[curFirePos.first+1][curFirePos.second] == INFINITY) {
                fireQueue.push(make_pair(curFirePos.first+1, curFirePos.second));
                fireM[curFirePos.first+1][curFirePos.second] = fireM[curFirePos.first][curFirePos.second]+1;
            }                
            if (curFirePos.second >= 0 && walls[curFirePos.first][curFirePos.second-1] == 0 && fireM[curFirePos.first][curFirePos.second-1] == INFINITY) {
                fireQueue.push(make_pair(curFirePos.first, curFirePos.second-1)); 
                fireM[curFirePos.first][curFirePos.second-1] = fireM[curFirePos.first][curFirePos.second]+1;            
            }
            if (curFirePos.second < c && walls[curFirePos.first][curFirePos.second+1] == 0 && fireM[curFirePos.first][curFirePos.second+1] == INFINITY) {
                fireQueue.push(make_pair(curFirePos.first, curFirePos.second+1));
                fireM[curFirePos.first][curFirePos.second+1] = fireM[curFirePos.first][curFirePos.second]+1;              
            }
        }
        /*cout << "Checking vars\n";
        printf("R: %d C: %d\n", r, c);*/
        /*cout << "Walls Matrix\n";
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                printf("%3d", walls[i][j]);
            }
            cout << endl;
        }
        cout << "Fire Matrix\n";
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                printf("%3d", fireM[i][j]);
            }
            cout << endl;
        }
        cout << "Joe's Matrix\n";
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                printf("%3d", joeM[i][j]);
            }
            cout << endl;
        }*/

        int min = INFINITY;
        //printf("Printing rows\n");        
        for (int i = 0; i < c; i++){
            //printf("%d ", joeM[0][i]);   
            //printf("%d\n", joeM[r-1][i]);                                       
            if (joeM[0][i] < fireM[0][i] && joeM[0][i]<min) {
                min = joeM[0][i];
            }
            if (joeM[r-1][i] < fireM[r-1][i] && joeM[r-1][i]<min) {
                min = joeM[r-1][i];
            }
        }
        //printf("Printing columns\n");
        for (int i = 0; i < r; i++){
            //printf("%d ", joeM[i][0]);   
            //printf("%d\n", joeM[i][c-1]);
            if (joeM[i][0] < fireM[i][0] && joeM[i][0]<min) {
                min = joeM[i][0];
            }
            if (joeM[i][c-1] < fireM[i][c-1] && joeM[i][c-1]<min) {
                min = joeM[i][c-1];
            }
        }
        if (min == INFINITY) cout << "IMPOSSIBLE\n";
        else cout << min+1 << endl;
        /*                      */
    }
}