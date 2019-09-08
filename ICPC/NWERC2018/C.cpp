#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1123;

int sz[maxn];
double x[maxn], y[maxn];
vector<vi> G;

int dfs_sz(int u, int p){
	sz[u] = 1;
	trav(v, G[u]){
		if(v != p) continue;
		sz[u] += dfs_sz(v, u);
	}
	return sz[u];
}

int centroid(int u){
	trav(v, G[u]){
		if(sz[v] > sz[u] / 2)
			return centroid(v);
	}
	return u;
}

void dfs(int u, int p, double angle, double max_angle){
	if(p == -1) max_angle = max_angle / sz(G[u]);
	else if(sz(G[u]) != 1) max_angle = max_angle / (sz(G[u]) - 1);
	int idx = 0;
	trav(v, G[u]){
		if(v == p) continue;
		x[v] = x[u] + cos(idx * max_angle + angle);
		y[v] = y[u] + sin(idx * max_angle + angle);
		dfs(v, u, idx * max_angle + angle, max_angle);
		idx++;
	}
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n;
	cin >> n;
	G.resize(n);
	cout.precision(7);
	cout << fixed;
	rep(i,0,n - 1){
		int u, v;
		cin >> u >> v;
		--u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout << sz(G) << '\n';
	dfs_sz(0, 0);
	int root = centroid(0);
	dfs(root, -1, 0, 2 * acos(-1));
	rep(i,0,n) cout << x[i] << " " << y[i] << "\n";
	G.clear();
	cout << sz(G) << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
