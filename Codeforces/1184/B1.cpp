#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	vector<pair<ll, ll> > b(m);
	for(int i = 0; i < n; ++ i) cin >> a[i];
	for(int i = 0; i < m; ++ i) cin >> b[i].first >> b[i].second;
	sort(b.begin(), b.end());
	for(int i = 1; i < m; ++ i) b[i].second += b[i - 1].second;
	for(int i = 0; i < n; ++ i){
		int idx = upper_bound(b.begin(), b.end(), make_pair(a[i], (ll)1e9 + 123)) - b.begin();
		cout << (idx ? b[idx - 1].second : 0) << ' ';
	}
}
