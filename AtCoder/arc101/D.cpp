#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct FT{
	int offset = 1e5 + 123;
	vector<ll> s;
	FT(int n): s(n + offset) {};
	void update(int idx, int val){
		idx += offset;
		for(;idx < (int)s.size(); idx |= idx + 1) s[idx] += val;
	}
	ll get(int idx){
		idx += offset;
		ll sum = 0;
		for(;idx > 0; idx &= idx - 1) sum += s[idx - 1];
		return sum;
	}
};

int main(){
	int n;
	cin >> n;
	vector<int> a(n), pref(n);
	for(int i = 0; i < n; ++ i) cin >> a[i];
	int l = 1, r = 1e9 + 123;
	while(l < r){
		FT ft(n);
		int mid = (l + r + 1) / 2;
		for(int i = 0; i < n; ++ i) pref[i] = (a[i] >= mid ? 1 : -1);
		for(int i = 1; i < n; ++ i) pref[i] += pref[i - 1];
		ll cnt = 0;
		ft.update(0, 1);
		for(int i = 0; i < n; ++ i){
			cnt += ft.get(pref[i] + 1);
			ft.update(pref[i], 1);
		}
		if(cnt >= (1ll * n * (n + 1) / 2 + 1) / 2) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';
}
