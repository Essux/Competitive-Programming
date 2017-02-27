#include <iostream>

using namespace std;

int main(){
    int k;
    while (cin >> k && k){
        int n, m;
        cin >> n >> m;
        while (k--){
            int x, y;
            cin >> x >> y;
            if (n==x || m==y) cout << "divisa";
            else {
                if (y>m) cout << 'N';
                else cout << 'S';
                if (x>n) cout << 'E';
                else cout << 'O';
            }
            cout << endl;
        }
    }
}