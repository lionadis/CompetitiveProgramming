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

const int maxn = 1123;
pair<ll, ll> a[maxn], b[maxn];
unordered_map<ll, int> cnt;

ll encode(pair<ll, ll> x){
	return ((x.F + (1<< 20)) << 24) + x.S + (1 << 20);
}

pair<ll, ll> decode(ll x){
	return {(x >> 24) - (1 << 20), (x % (1<<24) - (1 << 20))};
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n;
	cin >> n;
	rep(i,0,n) cin >> a[i].F >> a[i].S;
	rep(i,0,n) cin >> b[i].F >> b[i].S;
	rep(i,0,n) rep(j,0,n) cnt[encode({a[i].F + b[j].F, a[i].S + b[j].S})]++;
	ll ans = -1, ans_cnt = 0;
	trav(p, cnt) if(p.S > ans_cnt) ans = p.F, ans_cnt = p.S;
	cout << decode(ans).F << " " << decode(ans).S << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
