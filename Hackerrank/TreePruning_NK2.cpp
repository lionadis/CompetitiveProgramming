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
const int maxk = 223;
const ll inf = 1e18;
int head[maxn], nxt[maxn], to[maxn], e = 0;
ll dp[maxk][maxn], cost[maxn], a[maxn];
vi G[maxn];

void add_edge(int u, int v, int c){
	nxt[e] = head[u];
	head[u] = e;
	cost[e] = c;
	to[e++] = v;
}

ll dfs(int u, int p){
	trav(v, G[u]){
		if(p == v) continue;
		add_edge(u, v, a[v]);
	}
}

ll solve(int e, int k){
	if(k == -1) return -inf;
	if(e == -1) return 0;
	ll &res = dp[k][e];
	if(res != -1) return res;
	res = max(solve(nxt[e], k - 1);
	return res;
}


int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	memset(head, -1, sizeof head);
	memset(dp, -1, sizeof dp);
	int n, k;
	cin >> n >> k;
	rep(i,0, n) cin >> a[i + 1];
	rep(i,0,n - 1){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	G[0].push_back(1);
	G[1].push_back(0);
	dfs(0,0);
	cout << solve(head[0], k) << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
