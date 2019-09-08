#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v, cnt(2 * n + 1);
	vector<pair<int, int> > a(n);
	for(int i = 0;i < n; ++i){
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
		v.push_back(x);
		v.push_back(y);
	}
	sort(v.begin(), v.end());
	unique(v.begin(), v.end());
	for(int i = 0; i < n; ++i){
		int l = a[i].first = lower_bound(v.begin(), v.end(), a[i].first) - v.begin();
		int r = a[i].second = lower_bound(v.begin(), v.end(), a[i].second) - v.begin();
		cnt[l] ++, cnt[r + 1] --;
	}
	for(int i = 1; i < 2 * n; ++i) cnt[i] += cnt[i - 1];
	sort(a.begin(), a.end());
	cout << *max_element(cnt.begin() + a[n - 1].first, cnt.end());
}
