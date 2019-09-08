#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, cost_r, cost_p, dp[1000123];
ll f(ll p){
	if(p == 0) return (n == 1) ? 0 : 9e18;
	ll temp_n = n;
	ll cost = 0;
	while(temp_n > 1){
		cost += cost_r, cost += min(temp_n - 1, p) * cost_p;
		ll temp_nn = temp_n;
		temp_n /= (p + 1);
		if(temp_n) temp_n += (temp_nn % (p + 1));
	}
	return cost;
}

ll solve(ll n){
	if(n <= 1) return 0;
	ll &res = dp[n];
	if(~res) return res;
	res = 9e18;
	for(int i = 1; i < n; ++ i){
		ll cost = cost_r + cost_p * i + solve((n + i) / (i + 1));
		res = min(res, cost);
	}
	return res;
}

int main(){
	memset(dp, -1, sizeof dp);
	cin >> n >> cost_r >> cost_p;
	cout << solve(n) << '\n';
	// 100000 1000000000 1000000000
}
