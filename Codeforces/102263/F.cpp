#include <bits/stdc++.h>
using namespace std;
const int maxn = 1012;
int a[maxn], b[maxn], n, p;
int dp[maxn][maxn];
bool solve(int idx, int pos){
	if(idx == n - 1) return 1;
	int &res = dp[idx][pos];
	if(~res) return res;
	res = 0;
	int n_chairs = n - idx;
	int cw = (pos + a[idx]) % n_chairs, ccw = ((pos - a[idx]) % n_chairs + n_chairs) % n_chairs;
	if(cw != b[idx]) res |= solve(idx + 1, cw - (cw > b[idx]));
	if(ccw != b[idx]) res |= solve(idx + 1, ccw - (ccw > b[idx]));
	return res;
}
	
int main(){
	memset(dp, -1, sizeof dp);
	cin >> n >> p;
	p--;
	for(int i = 0; i < n - 1; ++ i) cin >> a[i];
	for(int i = 0; i < n - 1; ++ i){
		cin >> b[i];
		b[i]--;
		for(int j = 0; j < i; ++j) b[i] -= (b[i] > b[j]);
	}
	cout << (solve(0, p) ? "Yes":"No") << '\n';
}
