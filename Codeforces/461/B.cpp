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
const int mod = 1e9 + 7;
ll c[maxn], dp[2][maxn];
vi G[maxn];

void dfs(int u, int p){
	dp[c[u]][u] = 1;
	trav(v, G[u]){
		if(p == v) continue;
		dfs(v, u);
		dp[1][u] = dp[1][u] * (dp[0][v] + dp[1][v]) + dp[0][u] * dp[1][v]; dp[1][u] %= mod;
		dp[0][u] = dp[0][u] * (dp[0][v] + dp[1][v]); dp[0][u] %= mod;
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
	rep(i,1,n){
		int p;
		cin >> p;
		G[p].push_back(i);
		G[i].push_back(p);
	}
	rep(i,0,n) cin >> c[i];
	dfs(0, 0);
	cout << dp[1][0] << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
