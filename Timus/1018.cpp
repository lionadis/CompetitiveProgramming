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

const int N = 123;
const int inf = 1e9 + 7;
int head[N], nxt[N], to[N], cost[N], dp[N][N], e = 0;
vector<pii> G[N];

void add_edge(int u, int v, int c){
	nxt[e] = head[u];
	head[u] = e;
	cost[e] = c;
	to[e++] = v;
}

void dfs(int u, int par){
	trav(p, G[u]){
		if(p.F == par) continue;
		add_edge(u, p.F, p.S);
		dfs(p.F, u);
	}
}

int solve(int e, int k){
	if(k == 0) return 0;
	if(e == -1) return -inf;
	int &res = dp[e][k];
	if(res != -1) return res;
	res = solve(nxt[e], k);
	rep(i,0,k)	res = max(res, cost[e] + solve(head[to[e]], k - 1 - i) + solve(nxt[e], i));
	return res;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n, k;
	cin >> n >> k;
	memset(dp, -1, sizeof dp);
	memset(head, -1, sizeof head);
	rep(i,0,n - 1){
		int u, v, c;
		cin >> u >> v >> c;
		--u, --v;
		G[u].push_back({v, c});
		G[v].push_back({u, c});
	}
	dfs(0, 0);
	cout <<	solve(head[0], k) << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
