#include <bits/stdc++.h>

using namespace std;

struct I{
	int l, r, id;
};

int main(){
	int n, m;
	cin >> n >> m;
	vector<I> a(n);
	for(int i = 0; i < n; ++ i){
		int l, r;
		cin >> l >> r;
		a[i] = {l, r, i};
	}
	int cur = 1, idx = 0;
	sort(a.begin(), a.end(), [&](I a, I b){
		if(a.l  == b.l) return a.r < b.r;
		return a.l < b.l;
	});
	vector<int> ans;
	while(cur <= m){
		pair<int, int> max_r = {-1, -1};
		while(idx < n && a[idx].l <= cur) max_r = max(max_r, {a[idx].r, a[idx].id}), idx ++;
		if(max_r.first == -1){
			ans.clear();
			break;
		} else {
			ans.push_back(max_r.second);
			cur = max_r.first + 1;
		};
	}
	if(ans.empty()){
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << ans.size() << '\n';
		for(auto x:ans) cout << x + 1 << " ";
	}
}
