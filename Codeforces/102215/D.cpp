#include <bits/stdc++.h>
using namespace std;

const int maxn = 200213, lgn = 20;
int par[lgn][maxn], tin[maxn], tout[maxn], tot;
vector<vector<int> > G;

void dfs(int u, int p=1){
	tin[u] = tot ++;
	par[0][u] = p;
	for(int i = 1; i < lgn; ++ i) par[i][u] = par[i - 1][par[i - 1][u]];
	for(auto v:G[u]){
		if(v != p) dfs(v, u);
	}
	tout[u] = tot ++;
};

bool is_ancestor(int u, int v){
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
	if(is_ancestor(u, v)) return u;
	if(is_ancestor(v, u)) return v;
	for(int i = lgn - 1; i >= 0; --i){
		if(!is_ancestor(par[i][u], v)) u = par[i][u];
	}
	return par[0][u];
}

int main(){
	// freopen("test.in", "r", stdin);
	int n;
	cin >> n;
	G.resize(n + 1);
	for(int i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	int q;
	cin >> q;
	while(q--){
		int cnt_r, cnt_b, lca_r, lca_b;
		cin >> cnt_r >> cnt_b;
		vector<int> r(cnt_r), b(cnt_b);
		for(int i = 0; i < cnt_r; ++ i){
			cin >> r[i];
			if(i == 0) lca_r = r[i];
			lca_r = lca(lca_r, r[i]);
		}
		for(int i = 0; i < cnt_b; ++ i){
			cin >> b[i];
			if(i == 0) lca_b = b[i];
			lca_b = lca(lca_b, b[i]);
		}
		bool ans = true;
		if(is_ancestor(lca_r, lca_b)){
			for(auto u:r) ans &= !is_ancestor(lca_b, u);
		} else if(is_ancestor(lca_b, lca_r)){
			for(auto u:b) ans &= !is_ancestor(lca_r, u);
		}
		cout << (ans ? "YES":"NO") << '\n';
	}
}
