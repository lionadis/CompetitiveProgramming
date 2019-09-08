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

vi x, y;

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n, m;
	cin >> n >> m;
	rep(i,0,n){
		int v;
		cin >> v;
		y.push_back(v);
	}
	y.push_back(1e9);
	sort(all(y));
	rep(i,0,m){
		int x1, x2, y1;
		cin >> x1 >> x2 >> y1;
		if(x1 == 1) x.push_back(x2);
	}
	sort(all(x));
	int ans = 1e9;
	rep(i,0,sz(y)){
		int idx = lower_bound(all(x), y[i]) - x.begin();
		idx = sz(x) - idx;
		ans = min(i + idx, ans);
	}
	cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
