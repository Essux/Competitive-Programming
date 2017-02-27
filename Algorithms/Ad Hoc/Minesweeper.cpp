#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int rows, cols, field = 0;
    while (cin >> rows >> cols && rows != 0){
        field++;
        if (field>1) cout << endl;
        bool board[rows][cols];
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                board[i][j] = false;
            }
        }
        for (int actual_row = 0; actual_row<rows; actual_row++){
            string line;
            cin >> line;
            for (int i = 0; i<line.length(); i++){
                if (line[i] == '*')
                    board[actual_row][i] = true;
            }
        }
        int adj_mines[rows][cols];
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                adj_mines[i][j] = -1;
            }
        }
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                int neighbors = 0;
                if (board[i][j]) continue;
                if (i > 0 && j > 0 && board[i-1][j-1]) neighbors++;
                if (i > 0 && board[i-1][j]) neighbors++;
                if (i > 0 && j < cols-1 && board[i-1][j+1]) neighbors++;
                if (j > 0 && board[i][j-1]) neighbors++;
                if (j < cols-1 && board[i][j+1]) neighbors++;
                if (i < rows-1 && j > 0 && board[i+1][j-1]) neighbors++;
                if (i < rows-1 && board[i+1][j]) neighbors++;
                if (i < rows-1 && j < cols-1 && board[i+1][j+1]) neighbors++;
                adj_mines[i][j] = neighbors;
            }
        }
        cout << "Field #" << field << ":" << endl;
        for (int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                if (adj_mines[i][j] == -1) cout << '*';
                else cout << adj_mines[i][j];
            }
            cout << endl;
        }
    }
}