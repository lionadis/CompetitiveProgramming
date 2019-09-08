#include <bits/stdc++.h>
using namespace std;

struct UF{
	vector<int> e;
	UF(int n): e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	void join(int a,int b) {
		a = find(a), b = find(b);
		if(a == b) return;
		if(e[a] > e[b]) swap(a, b);
		e[a] += e[b], e[b] = a;
	}
};

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), id(n + 1);
	UF uf(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i], id[a[i]] = i;
	for(int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		uf.join(u, v);
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(uf.same_set(i, id[i])) ans ++;
	}
	cout << ans << '\n';
}
