// Codeforces Round #363 (Div. 1) - Problem A
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int a[MAXN];
int n;
bool sp[] = {false, false, true, true};
bool pr[] = {false, true, false, true};
bool dsp[MAXN], dpr[MAXN];
int memo[MAXN][2][2];

int dp(int id, bool sport, bool prog) {
	if (id>=n) return 0;
	int &cmemo = memo[id][sport][prog];
	if (cmemo!=-1) return cmemo;
	int ans = dp(id+1, false, false)+1;
	if (!sport && dsp[id]) ans = min(ans, dp(id+1, true, false));
	if (!prog && dpr[id]) ans = min(ans, dp(id+1, false, true));
	return cmemo = ans;
}

int main() {
	cin >> n;
	memset(memo, -1, sizeof(memo));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dsp[i] = sp[a[i]];
		dpr[i] = pr[a[i]];
	}
	cout << dp(0, false, false) << endl;
}