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

const int maxn = 8123;
const int maxk = 812;
const ll inf = 1e18;
ll a[maxn], dp[maxk][maxn];

ll query(int l, int r){
	return (a[r] - a[l - 1]) * (r - l + 1);
}

void solve(int k, int l, int r, int optl, int optr){
	if(l > r) return;
	int mid = (l + r) / 2;
	pair<ll, int> best = {inf, -1};
	rep(i,optl, min(mid, optr) + 1) best = min(best, {dp[k - 1][i] + query(i + 1, mid), i});
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
	int n, k;
	cin >> n >> k;
	rep(i,1,n + 1) cin >> a[i], a[i] += a[i - 1];
	rep(i,1,n + 1) dp[1][i] = query(1, i);
	rep(i,2, k + 1) solve(i, 1, n, 0, n);
	cout << dp[k][n] << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
