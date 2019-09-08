#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

const int maxn = 100123;
long long a[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	setprecision(12);
	cout << fixed;
	long long n, k, m;
	cin >> n >> k >> m;
	rep(i,0,n) cin >> a[i];
	sort(a, a + n);
	rep(i,0,n - 1) a[n - i - 2] += a[n - i - 1];
	double ans = 0;
	rep(i,0,min(n, m + 1)){
		double curr_ans = 1.0 * (a[i] + min(m - i, k * (n - i) ))/ (n - i);
		ans = max(curr_ans, ans);
	}
	cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
