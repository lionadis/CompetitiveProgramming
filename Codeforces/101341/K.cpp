#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = (int)1e9+7;
int main(){
	// freopen("test.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<ll> > a(n, vector<ll>(n)), b(n, vector<ll>(n)), c(n, vector<ll>(n));
	for(int i = 0; i < n; ++ i) for(int j = 0; j < n; ++ j) cin >> a[i][j];
	for(int i = 0; i < n; ++ i) for(int j = 0; j < n; ++ j) cin >> b[i][j];
	for(int i = 0; i < n; ++ i) for(int j = 0; j < n; ++ j) cin >> c[i][j];
	int k = 30;
	while(k--){
		vector<ll> r(n), r1(n), lhs(n), rhs(n);
		for(int i = 0; i < n; ++ i) r[i] = rand()%2;
		for(int i = 0; i < n; ++ i)  for(int j = 0; j < n; ++ j) r1[i] += r[j] * b[i][j], r1[i] %= mod;
		for(int i = 0; i < n; ++ i)  for(int j = 0; j < n; ++ j) lhs[i] += r1[j] * a[i][j], lhs[i] %= mod;
		for(int i = 0; i < n; ++ i)  for(int j = 0; j < n; ++ j) rhs[i] += r[j] * c[i][j], rhs[i] %= mod;
		for(int i = 0; i < n; ++ i) if(rhs[i] != lhs[i]) return cout << "NO\n", 0;
	}
	cout << "YES\n";
}
