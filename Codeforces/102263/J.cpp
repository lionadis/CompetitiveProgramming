#include <bits/stdc++.h>
using namespace std;
string s;
const int maxn = 100123;
int dp[maxn][2], n;
int solve(int idx, int state){
	if(idx >= n) return 0;
	int &res = dp[idx][state];
	if(~res) return res;
	res = 0;
	res = (int)(s[idx] - '0') + solve(idx + 1, 0);
	if(state == 0) return res = min(res, (int)('9' - s[idx]) + 2 + solve(idx + 1, 1));
	return res = min(res, (int)('9' - s[idx]) + solve(idx + 1, 1));
}
int main(){
	memset(dp, -1, sizeof dp);
	cin >> s;
	n = (int)s.size();
	cout << solve(0, 0) << '\n';
}
