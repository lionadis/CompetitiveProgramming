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
int n, l, r, sz[maxn], bit[maxn], one;
ll ans;
bool vis[maxn];
vector<vi> G;

void reset(){
	G.clear();
	G.resize(n);
	fill(sz, sz + n, 0);
	fill(vis, vis + n, false);
	fill(bit, bit + n, 0);
	ans = 0;
}

void dfs_sz(int u, int p){
	sz[u] = 1;
	trav(v, G[u]){
		if(v == p) continue;
		dfs_sz(v, u);
		sz[u] += sz[v];
	}
}

int centroid(int u){
	trav(v, G[u]){
		if(!vis[v] && sz[v] > sz[u] / 2){
			sz[u] -= sz[v];
			sz[v] += sz[u];
			return centroid(v);
		}
	}
	return u;
}

void inc(int x){
	for(;x<=n;x+=x&-x) bit[x]+=one;
}

int query(int x){
	int sum = 0;
	for(;x>0;x-=x&-x) sum += bit[x];
	return sum;
}

int query(int l, int r){
	return query(r) - query(l - 1);
}

void solve(int x){
	ans += query(max(l - x, 0), max(r - x, 0));
}

void dfs(int u, int p, int h, int op){
	(op) ? solve(h) : inc(h);
	trav(v, G[u]){
		if(v == p || vis[v]) continue;
		dfs(v, u, h + 1, op);
	}
}

void decompose(int u){
	u = centroid(u);
	vis[u] = 1;
	one = 1;
	trav(v, G[u]){
		if(!vis[v]){
			dfs(v, v, 1, 1), dfs(v, v, 1, 0);
		}
	}
	solve(0);
	one = -1;
	trav(v, G[u]){
		if(!vis[v]){
			 dfs(v, v, 1, 0);
		}
	}
	trav(v, G[u]){
		if(!vis[v]) decompose(v);
	}
}


int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    freopen("awesome.in","r",stdin);
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int t;
	cin >> t;
	while(t--){
		cin >> n >> l >> r;
		reset();
		l = n - 1 - l;
		r = n - 1 - r;
		swap(l, r);
		rep(i,0,n - 1){
			int u, v;
			cin >> u >> v;
			--u, --v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs_sz(0,0);
		decompose(0);
		cout << ans << '\n';
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
