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

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n, x;
	cin >> n >> x;
	bool is_inf = false;
	int ans = 0;
	if(2 * x == n) ans ++;
	rep(i,0,n){
		int y;
		cin >> y;
		if( 2 * y == n) ans ++;
		if(2 * x == n && n == 2 * y) is_inf = true;
		if((2 * x  < n && n  < 2 * y) || (2 * x > n && n > 2 * y)) ans++;
		x = y;
	}
	if(is_inf) cout << "INF\n";
	else cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}