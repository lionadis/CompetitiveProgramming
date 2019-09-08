#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long int dp[3000][3000];
long long int C(int n, int k){
	if(dp[n][k] != -1)return dp[n][k];
	if(n == k || k == 0)return dp[n][k] = 1;
	return dp[n][k] = (C(n - 1, k - 1) + C(n - 1, k)) % MOD; 
}
long long int fexp(int a, int b){
		if(b == 0)return 1LL;
		long long int res = fexp(a, b / 2);
		res = (res * res) % MOD;
		if(b % 2 == 1)res = (res * a) % MOD;
		return res;
}
int main(){
	int n, k, p;
	cin >> n >> k;
	for(int i = 0; i < n - 1; i++)cin >> p;
	memset(dp, -1, sizeof dp);
	long long int result = (k * fexp(k - 1, n - 1)) % MOD;
	for(int i = 1; i < k; i++){
		result -= (((C(k, i) * (k - i)) % MOD) * fexp(k - i - 1, n - 1)) % MOD;
	}
	cout << result << '\n';

}
