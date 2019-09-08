#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n), cant_pass(n + 1);
	vector<vector<int> > g(n + 1);
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	reverse(a.begin(), a.end());
	cant_pass[a[0]] = 1;
	int ans = 1;
	for(int i = 1; i < n; ++i){
		int cnt = 0;
		for(int v : g[a[i]]){
			if(cant_pass[v]) cnt++;
		}
		if(ans != cnt) ans++, cant_pass[a[i]] = 1;;
	}
	cout << n - ans << '\n';
}

