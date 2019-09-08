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

const int maxn = 100123;
int ans[maxn], f[maxn], tot = 0;
vi G[maxn];

void dfs(int k, int u, int p){
	int mx1 = 0, mx2 = 0;
	trav(v, G[u]){
		if(v == p) continue;
		dfs(k, v, u);
		if(f[v] > mx1) mx2 = mx1, mx1 = f[v];
		else mx2 = max(mx2, f[v]);
	}
	if(mx1 + mx2 + 1>= k) f[u] = 0, tot++;
	else f[u] = mx1  + 1;
}

void solve(int l, int r, int ansl, int ansr){
	if(l > r) return;
	if(ansl == ansr){
		rep(i,l,r + 1) ans[i] = ansl;
		return;
	}
	rep(i,l, r + 1) f[i] = 0;
	tot = 0;
	int mid = (l + r) / 2;
	dfs(mid, 0, 0);
	ans[mid] = tot;
	solve(l, mid - 1, tot, ansr);
	solve(mid + 1, r, ansl, tot);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n;
	cin >> n;
	rep(i,0,n - 1){
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	solve(1, n, 0, n);
	rep(i,1, n + 1) cout << ans[i] << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
