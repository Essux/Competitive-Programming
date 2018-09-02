// UVa 13009 - Fence The Vegetables Fail
#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y, value;
    point() {}
    point(int _x, int _y) : x(_x), y(_y) {}
    bool operator< (point other) const {
        if (x != other.x) return x < other.x;
        return y <= other.y;
    }
};

class FenwickTree {
    private: vector<int> ft;
    public:
        FenwickTree(int n) {ft.assign(n+1, 0);}
        int rsq(int b){
            int sum = 0;
            for (; b; b -= b & (-b)) sum += ft[b];
            return sum;
        }
        int rsq(int a, int b) {
            return rsq(b) - (a <= 1 ? 0:rsq(a-1));
        }
        void adjust(int k, int v){
            for (; k < (int) ft.size(); k += k & (-k)) ft[k] += v;
        }
};

int main() {
    int p, v;
    while (cin >> p >> v) {
        vector<point> plants, fence;
        set<int> ys;
        for (int i = 0; i < p; i++) {
            int x, y; cin >> x >> y;
            plants.push_back(point(x, y));
            plants[i].value = i+1;
            ys.insert(y);
        }
        for (int i = 0; i < v; i++) {
            int x, y; cin >> x >> y;
            fence.push_back(point(x, y));
            ys.insert(y);
        }
        sort(fence.begin(), fence.end());
        sort(plants.begin(), plants.end());

        map<int, int> ytoi;
        int counter = 1;
        for (set<int>::iterator it = ys.begin(); it!=ys.end(); it++)
            ytoi[*it] = counter, counter+=2;

        int id = 0, first_x = fence[0].x;
        bool in = false;
        FenwickTree ft(ys.size()*2);
        long long ans = 0;
        for (int i = 0; i < p; i++) {
            while (id < v && fence[id].x <= plants[i].x) {
                if (fence[id].x==first_x) in = !in;
                else in = true;
                int l = ytoi[fence[id].y];
                int r = ytoi[fence[id+1].y];
                ft.adjust(l, 1);
                ft.adjust(r+1, -1);
                id += 2;
            }
            int t = ytoi[plants[i].y]+1;
            ans += (1-(1&ft.rsq(t)))*plants[i].value;
        }
        cout << ans << '\n';
    }
}