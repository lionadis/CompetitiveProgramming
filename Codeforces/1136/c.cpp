#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n + m), b(n + m);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			int x;
			cin >> x;
			a[i + j].push_back(x);
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			int x;
			cin >> x;
			b[i + j].push_back(x);
		}
	}
	bool ans = true;
	for(int i = 0; i < n + m; ++i){
		sort(a[i].begin(), a[i].end());
		sort(b[i].begin(), b[i].end());
		ans &= a[i] == b[i];
	}
	cout << (ans ? "YES\n":"NO\n");
}
	
