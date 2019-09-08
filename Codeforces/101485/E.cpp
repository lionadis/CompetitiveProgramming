#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2512;
ll a[maxn], b[maxn], matchL[maxn], matchR[3 * maxn], vis[maxn];
vector<vector<int> > G;

bool dfs(int u){
	if(vis[u]) return false;
	vis[u] = true;
	for(auto &v:G[u]){
		if(matchR[v] == -1 || dfs(matchR[v])){
			matchR[v] = u, matchL[u] = v;
			return true;
		}
	}
	return false;
}

int main(){
	int n;
	cin >> n;
	G.resize(n);
	vector<ll> v;
	for(int i = 0; i < n; ++ i){
		cin >> a[i] >> b[i];
		v.push_back(a[i] + b[i]);
		v.push_back(a[i] - b[i]);
		v.push_back(a[i] * b[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i = 0; i < n; ++ i){
		int v_idx = lower_bound(v.begin(), v.end(), a[i] + b[i]) - v.begin();
		G[i].push_back(v_idx);
		v_idx = lower_bound(v.begin(), v.end(), a[i] - b[i]) - v.begin();
		G[i].push_back(v_idx);
		v_idx = lower_bound(v.begin(), v.end(), a[i] * b[i]) - v.begin();
		G[i].push_back(v_idx);
	}
	memset(matchR, -1, sizeof matchR); 
	for(int i = 0; i < n; ++ i){
		memset(vis, 0, sizeof vis);
		if(!dfs(i)) return cout << "impossible\n", 0;
	}
	for(int i = 0; i < n; ++ i){
		if(a[i] + b[i] == v[matchL[i]]) cout << a[i] << " + " << b[i] << " = " << v[matchL[i]] << '\n';
		else if(a[i] - b[i] == v[matchL[i]]) cout << a[i] << " - " << b[i] << " = " << v[matchL[i]] << '\n';
		else if(a[i] * b[i] == v[matchL[i]]) cout << a[i] << " * " << b[i] << " = " << v[matchL[i]] << '\n';
	}
}
		

