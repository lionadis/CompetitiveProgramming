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

const int maxn = 100123;
int n, m, a[maxn], smaller[maxn], bigger[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	cin >> n >> m;
	rep(i,0,n){
		int l, r;
		cin >> l >> r;
		a[l]++, a[r + 1]--;
	}
	rep(i,1,m + 1) a[i] += a[i - 1];
	vi res;
	rep(i,1,m + 1){
		auto it = upper_bound(all(res), a[i]);
		smaller[i] = it - res.begin();
		if(it == res.end()) res.push_back(a[i]);
		else *it = a[i];
	}
	res.clear();
	for(int i = m;i;--i){
		auto it = upper_bound(all(res), a[i]);
		bigger[i] = it - res.begin();

		else *it = a[i];
	}
	int ans = 0;
	rep(i,1,m + 1) ans = max(ans, bigger[i] + smaller[i] + 1);
	cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
