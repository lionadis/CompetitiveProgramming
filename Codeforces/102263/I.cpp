#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; ++ i) cin >> a[i];
	sort(a.begin(), a.end());
	vector<ll> ans(1, 0);
	ll l = 0, r = n - 1, res = 0;
	while(l <= r){
		ans.push_back(ans.back() + res);
		res += a[r] - a[l];
		ans.push_back(ans.back() + res);
		l++, r--;
	}
	for(int i = 2; i <= n; ++ i) cout << ans[i] << " ";
}
