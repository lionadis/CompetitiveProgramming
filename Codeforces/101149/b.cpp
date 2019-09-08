#include <bits/stdc++.h> 

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<pair<int, int> > a(n);
	for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end(), [&](const pair<int, int> &x, const pair<int, int> &y){
					if (x.second - x.first != y.second - y.first)
						return x.first - x.second > y.first - y.second;
					return x.first > y.first;
				});
	long long ans = 0, left = 0;
	for(int i = 0; i < n; ++i){
		ans += max(a[i].first - left, 0LL);
		left = max(left - (a[i].first - a[i].second), 1ll * a[i].first - a[i].second);
	}
	cout << ans << '\n';
}
