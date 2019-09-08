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

ll hhy(ll x, ll y, ll w1, ll w2, ll poin){
	ll ans = ((y - w2) * (y - w2) + (x - w1) * (x - w1)) - poin;
	return ans;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	ll p, q, r, s, t;
	cin >> p >> q >> r;
	s = hhy(q,r,1,1,1);
	t = hhy(q,r,p,p,0);
	cout << s << " " << t << '\n';
	if(s < t) cout << "White\n";
	else cout << "White\n";
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
