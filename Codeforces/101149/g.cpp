#include <bits/stdc++.h>

using namespace std;

struct node{
	int w, c, id;
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<node> a(n);
	vector<int> ans(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i].w >> a[i].c;
		a[i].id = i;
	}
	int m;
	cin >> m;
	vector<node> b(m);
	for(int i = 0; i < m; ++i){
		cin >> b[i].w >> b[i].c;
		b[i].id = i;
	}
	sort(a.begin(), a.end(), [&](node &x, node &y){
		return x.w > y.w;
	});
	sort(b.begin(), b.end(), [&](node &x, node &y){
		return x.w > y.w;
	});
	set<pair<int, int> > s;
	int j = 0;
	for(int i = 0; i < n; ++i){
		while(j < m && a[i].w <= b[j].w){
			s.insert({b[j].c, b[j].id});
			j++;
		}
		auto it = s.lower_bound({a[i].c, 0});
		if (it == s.end()) return cout << "-1\n", 0;
		ans[a[i].id] = it->second + 1;
		s.erase(it);
	}
	for(int x:ans) cout << x << " ";
	cout << '\n';
	
}
