#include <iostream>
#include <string>

using namespace std;

int rows, cols;

int shouldIMove(bool warnings[][53], char orientation, int x, int y){
    // 1 -> Already used, don't 2-> Not yet used, flagged 3->No problem here
    if (x == 0 && orientation == 'W'){      
        if (!warnings[x][y]){
            warnings[x][y] = true;
            return 2;
        }
        else return 1;
    }
    else if (x == cols && orientation == 'E'){   
        if(!warnings[x][y]){
            warnings[x][y] = true;
            return 2;
        }
        else return 1;
    }
    else if (y == 0 && orientation == 'S'){
        if(!warnings[x][y]){
            warnings[x][y] = true;
            return 2;
        }
        else return 1;
    }
    else if (y == rows && orientation == 'N'){
        if(!warnings[x][y]){
            warnings[x][y] = true;
            return 2;
        }
        else return 1;
    }
    return 3;
}

char rotate(char orientation, char side){
    if (side == 'R'){
        if (orientation == 'N') return 'E';
        if (orientation == 'E') return 'S';
        if (orientation == 'S') return 'W';
        return 'N';
    }
    if (orientation == 'N') return 'W';
    if (orientation == 'E') return 'N';
    if (orientation == 'S') return 'E';
    return 'S';
}

bool robotMoves(bool warnings[][53]){
    int x, y;
    char orientation;
    string inst;
    bool lost = false;
    if (!(cin >> x >> y >> orientation >> inst)) return false;
    for(string::iterator it = inst.begin(); it != inst.end() && !lost; it++){
        if (*it == 'F'){
            int shouldMove = shouldIMove(warnings, orientation, x, y);
            switch (shouldMove){
                case 3:
                    switch (orientation){
                        case 'N': y++;
                        break;
                        case 'E': x++;
                        break;
                        case 'S': y--;
                        break;
                        case 'W': x--;
                        break;
                    }
                    break;
                case 2:
                    lost = true;
                    break;
                case 1:
                    break;
            }
            
        }
        else orientation = rotate(orientation, *it);
    }
    cout << x << ' ' << y << ' ' << orientation << (lost ? " LOST" : "")<< endl;
    return true;
}

int main(){
    cin >> cols >> rows;
    bool warnings[cols+1][53];
    for (int i = 0; i <= cols; i++){
        for (int j = 0; j <= rows; j++){
            warnings[i][j] = false;
        }
    }
    while (robotMoves(warnings)){}
}