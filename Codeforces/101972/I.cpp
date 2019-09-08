#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = (int) 1e9 + 7, maxn = 100123;
ll fact[maxn], inv_fact[maxn];
ll bin_pow(ll x, ll y){
	ll a = 1, b = x;
	while(y){
		if(y&1) a *= b, a %= mod;
		b = (b * b) % mod;
		y >>= 1;
	}
	return a;
}
ll c(int n, int k){
	return (((fact[n] * inv_fact[n - k]) % mod) * inv_fact[k]) % mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	fact[0] = fact[1] = 1;
	for(int i = 2; i < maxn; ++ i) fact[i] = (fact[i - 1] * i) % mod;
	for(int i = 0; i < maxn; ++ i) inv_fact[i] = bin_pow(fact[i], mod - 2);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		cout << c(n, m - 1) << " " << c(n - 1, m - 1) << '\n';
	}
}
	
