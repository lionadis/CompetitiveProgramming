#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int a[123];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n, k, sum = 0, ans = 0;
	cin >> n >> k;
	rep(i,0,n) cin >> a[i], sum += a[i];
	rep(b,0,n){
		int tmp = 0;
		for(int i = b; i < n; i += k) tmp += a[i];
		for(int i = b - k; i >= 0; i -= k) tmp += a[i];
		ans = max(ans, abs(sum - tmp));
	}
	cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
