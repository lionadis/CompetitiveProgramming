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

const int maxn = 50123;
const int maxk = 123;
const int mod = 1e9 + 7;
ll a[maxn], dp[2 * maxk + 12][maxn], n, k;
vector<vi> G;

void dfs(int u, int p){
	dp[a[u]][u] = 1;
	trav(v, G[u]){
		if(v == p) continue;
		dfs(v, u);
		for(int i=k;i>=0;--i){
			for(int j=k - i;j>=0;--j){
				dp[i + j][u] += dp[i][u] * dp[j][v];
				dp[i + j][u] %= mod;
			}
		}
	}
}


int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int t;
	cin >> t;
	while(t--){
		memset(dp, 0, sizeof dp);
		cin >> n >> k;
		G.clear();
		G.resize(n);
		rep(i,0,n) cin >> a[i];
		rep(i,0,n - 1){
			int u, v;
			cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(0, 0);
		int ans = 0;
		rep(i,0,n) ans += dp[k][i], ans %= mod;
		cout << ans << '\n';
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
