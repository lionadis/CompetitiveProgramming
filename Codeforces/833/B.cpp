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

const int maxn = 35123;
const int maxm = 52;
const int inf = 1e9 + 7;
int a[maxn], dp[maxm][maxn], cnt[maxn], ans, L = 1, R;

int query(int l, int r){
	while(l < L) ans+=++cnt[a[--L]]==1;
	while(l > L) ans-=--cnt[a[L++]]==0;
	while(r > R) ans+=++cnt[a[++R]]==1;
	while(r < R) ans-=--cnt[a[R--]]==0;
	return ans;
}

void solve(int k, int l, int r, int optl, int optr){
	if(l > r) return;
	int mid = (l + r) / 2;
	pii best = {-inf, -1};
	rep(i,optl,min(mid, optr) + 1) best = max(best, {dp[k - 1][i] + query(i + 1, mid), i});
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
	int n, m;
	cin >> n >> m;
	rep(i,1,n + 1) cin >> a[i];
	rep(i,1,m + 1) solve(i, 1, n, 0, n);
	cout << dp[m][n] << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
