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
ll a[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		rep(i,0,n) cin >> a[i];
		int ans = 0;
		rep(i,0,n){
			ll s = 0, lcm = 1;
			rep(j,i,n){
				s += a[j];
				lcm = lcm / __gcd(a[j], lcm) * a[j];
				if(lcm > 1e13) break;
				if(s % lcm == 0) ans++;
			}
		}
		cout << ans << '\n';
	}

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
