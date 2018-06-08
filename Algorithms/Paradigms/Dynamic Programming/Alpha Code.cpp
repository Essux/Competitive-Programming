// SPOJ - ACODE
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5300;

string st;
int n;
ll memo[MAXN];

bool can2(int id) {
    if (st[id]=='0') return false;
    if (st[id]=='1') return true;
    if (st[id]=='2' && id<n-1 && st[id+1]<='6') return true;
    return false;
}

ll dp(int id) {
    if (id==n-1) return st[id]!='0';
    if (id>n-1) return 1;
    ll &cm = memo[id];
    if (cm!=-1) return cm;
    if (st[id]=='0') return cm = 0;
    cm = dp(id+1);
    if (can2(id)) cm += dp(id+2);
    return cm;
}

int main() {
    while (cin >> st && st!="0") {
        n = st.size();
        memset(memo, -1, sizeof(memo));
        cout << dp(0) << endl;
    }
}