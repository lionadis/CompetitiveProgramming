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

const int maxn = 6123;
int a[maxn], dp[2][maxn];
bool is_root[maxn];
vi G[maxn];

int solve(int u, int taken){
	int &res = dp[taken][u];
	if(~res) return res;
	int ans1 = 0, ans2 = 0;
	trav(v, G[u]){
		ans1 += solve(v, 0);
		if(!taken) ans2 += solve(v, 1);
	}
	if(!taken) ans2 += a[u];
	return res = max(ans1, ans2);
}
	
int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	memset(dp, -1, sizeof dp);
	fill(is_root, is_root + maxn, true);
	int n;
	cin >> n;
	rep(i,0,n) cin >> a[i];
	rep(i,0,n - 1){
		 int u, v;
		 cin >> u >> v;
		 --u, --v;
		 is_root[u] = false;
		 G[v].push_back(u);
	}
	int root = -1;
	rep(i,0,n) if(is_root[i]) root = i;
	cout << solve(root, 0) << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
