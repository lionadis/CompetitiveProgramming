#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m, cnt = 0;
	cin >> n >> m;
	vector<vector<pair<int, int> > > a(n);
	for(int i = 0; i < n; ++ i){
		int x;
		cin >> x;
		for(int j = 2; j * j <= x; ++ j){
			while(x % j == 0) a[i].push_back({j, cnt++}), x /= j;
		}
		if(x != 1) a[i].push_back({x, cnt++});
	}
	vector<vector<int> > g(cnt);
	for(int i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v;
		--u, -- v;
		if(v % 2 == 0) swap(u, v);
		for(auto x:a[u]){
			for(auto y:a[v]){
				if(x.first == y.first) g[x.second].push_back(y.second);
			}
		}
	}
	int ans = 0;
	vector<int> match(cnt, -1);
	vector<bool> vis(cnt);
	function<int(int)> dfs = [&](int u){
		if(vis[u]) return false;
		vis[u] = true;
		for(auto v:g[u]){
			if(match[v] == -1 || dfs(match[v])){
				match[v] = u;
				return true;
			}
		}
		return false;
	};
	for(int i = 0; i < cnt; ++ i){
		fill(vis.begin(), vis.end(), false);
		if(dfs(i)) ans ++;
	}
	cout << ans << '\n';
}
			
