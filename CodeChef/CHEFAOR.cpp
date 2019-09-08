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

const int maxn = 5123;
const int lgn = 31;
const ll inf = 1e18;
int a[maxn][maxn], cnt[31], L, R = 0;
ll dp[maxn][maxn];

void solve(int k, int l, int r, int optl, int optr){
	if(l > r) return;
	int mid = (l + r) / 2;
	pair<ll, int> best = {-inf, -1};
	rep(i, optl, min(mid, optr) + 1) best = max(best, {dp[k - 1][i] + a[i + 1][mid], i});
	dp[k][mid] = best.F;
	solve(k, l, mid - 1, optl, best.S);
	solve(k, mid + 1, r, best.S, optr);
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
		L = 1, R = 0;
		memset(cnt, 0, sizeof cnt);
		int n, k;
		cin >> n >> k;
		rep(i,1,n + 1) cin >> a[i][i];
		rep(i,1,n + 1) rep(j, i + 1, n + 1) a[i][j] = a[i][j - 1] | a[j][j];
		rep(i,1,k + 1) solve(i, 1, n, 0, n);
		cout << dp[k][n] << '\n';
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
