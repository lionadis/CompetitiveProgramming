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

const int maxn = 200123;
int a[maxn], n;

ll f(int l, int r, int x){
	ll ans = 0;
	rep(i,l,r + 1) ans += abs(x + i - a[i]);
	return ans;
}

ll solve(int l, int r){
	int x = -200000, y = 200000;
	while(y - x >= 5){
		int mid = (x + y) / 2;
		if(f(l, r, mid) > f(l, r, mid + 1)) x = mid;
		else y = mid + 1;
	}
	rep(i,x + 1, y + 1) if(f(l, r, x) > f(l, r, i)) x = i;
	rep(i,l, r + 1) cout << i + x << " ";
	cout << '\n';
	return f(l, r, x);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	cin >> n;
	rep(i,0,n) cin >> a[i];
	sort(a, a + n);
	int last_block
	rep(i,0,n - 1){	
		if(a[i + 1] - a[i] > n / 2) {	
			int ans = solve(0, i) + solve(i + 1, n - 1);
			cout << ans << '\n';
			return  0;
		}
		
	}
	cout << solve(0,n - 1) << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
