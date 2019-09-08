#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll pow_n(ll x, int y){
	ll res = 1;
	for(int i = 0; i < y; ++ i) res *= x;
	return res;
}
 
ll nth_sqrt(ll n, int p){
	int l = 0, r = pow((double)(n + 123), 1.0/p);
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(pow_n(mid, p) <= n) l = mid;
		else r = mid - 1;
	}
	return l;
}
 
int main(){
	freopen("little.in", "rt", stdin);
	freopen("little.out", "wt", stdout);
	ll n, ans = 0;
	cin >> n;
	if(n == 1) return cout << "-1\n", 0;
	for(int k = 1; k < 64; ++ k){
		ll base = n;
		if(k != 1) base = nth_sqrt(n, k);
		if(base == 1) break;
		ll target = pow_n(base, k);
		bool reachable = true;
		int l = k;
		while(target != n && l --){
			target /= base;
			target *= (base + 1);
			if(target > n){
				reachable = false;
				break;
			}
		}
		if(base == 2 && l == k) return cout << "-1\n", 0;
		if(reachable){
			ans ++;
		}
	}
	cout << ans << '\n';
	for(int k = 1; k < 64; ++ k){
		ll base = n;
		if(k != 1) base = nth_sqrt(n, k);
		if(base == 1) break;
		ll target = pow_n(base, k);
		bool reachable = true;
		int l = k;
		while(target != n && l --){
			target /= base;
			target *= (base + 1);
			if(target > n){
				reachable = false;
				break;
			}
		}
		if(reachable){
			cout << k << ' ';
			for(int i = 0; i < l; ++ i) cout << base << ' ';
			for(int i = l; i < k; ++ i) cout << base + 1 << ' ';
			cout << '\n';
		}
	}
}
