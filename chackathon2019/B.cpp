#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll a[1012][1012], dp[1012][1012][3], n;

ll solve(int x, int y, int dir){
	if(x < 0 || x >= n) return 1e18;
	if(y == n) return a[x][y];
	ll &res = dp[x][y][dir];
	if(~res) return res;
	res = a[x][y] + solve(x, y + 1, 0);
	// 0 jdid
	// 1 tala3
	// 2 habet
	if(dir != 1) res = min(res, a[x][y] + solve(x + 1, y, 2));
	if(dir != 2) res = min(res, a[x][y] + solve(x - 1, y, 1));
	return res;
}
int main(){
	freopen("test.in", "r", stdin);
	memset(dp, -1, sizeof dp);
	cin >> n;
	for(int i = 0; i < n; ++ i){
		for(int j = 1; j <= n; ++ j){
			cin >> a[i][j];
		}
	}
	cout << solve(0, 0, 0) << '\n';
}
