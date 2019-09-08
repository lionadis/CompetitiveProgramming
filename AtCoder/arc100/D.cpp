#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	int n;
	cin >> n;
	vector<ll> a(n), pref(n + 1);
	for(int i = 0; i < n; ++ i) cin >> a[i];
	pref[1] = a[0];
	for(int i = 2; i <= n; ++ i) pref[i] = pref[i - 1] + a[i - 1];
	int p1 = 1, p3 = 3;
	ll ans = 1e18;
	for(int p2 = 2; p2 <= n - 1; ++ p2){
		while(pref[p2] - pref[p1] > pref[p1]) p1++;
		while(pref[n] - pref[p3] > pref[p3] - pref[p2]) p3++;
		ll max_sub = max({pref[p1], pref[p2] - pref[p1], pref[p3] - pref[p2], pref[n] - pref[p3]});
		ll min_sub = min({pref[p1], pref[p2] - pref[p1], pref[p3] - pref[p2], pref[n] - pref[p3]});
		ans = min(ans, max_sub - min_sub);
		
		p1 --;
		max_sub = max({pref[p1], pref[p2] - pref[p1], pref[p3] - pref[p2], pref[n] - pref[p3]});
		min_sub = min({pref[p1], pref[p2] - pref[p1], pref[p3] - pref[p2], pref[n] - pref[p3]});
		ans = min(ans, max_sub - min_sub);
		
		p1 ++;
		p3 --;
		max_sub = max({pref[p1], pref[p2] - pref[p1], pref[p3] - pref[p2], pref[n] - pref[p3]});
		min_sub = min({pref[p1], pref[p2] - pref[p1], pref[p3] - pref[p2], pref[n] - pref[p3]});
		ans = min(ans, max_sub - min_sub);
		
		p1 --;
		max_sub = max({pref[p1], pref[p2] - pref[p1], pref[p3] - pref[p2], pref[n] - pref[p3]});
		min_sub = min({pref[p1], pref[p2] - pref[p1], pref[p3] - pref[p2], pref[n] - pref[p3]});
		ans = min(ans, max_sub - min_sub);
		
	}
	cout << ans << '\n';
}
		
		
		
