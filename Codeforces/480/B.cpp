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
int a[maxn];
unordered_map<ll, bool> vis;

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n, l, x, y;
	cin >> n >> l >> x >> y;
	rep(i,0,n) cin >> a[i], vis[a[i]] = true;
	bool flag_x = false, flag_y = false;
	rep(i,1,n){
		if(vis[a[i] - x]) flag_x = true;
		if(vis[a[i] - y]) flag_y = true;
	}
	if(!flag_x && !flag_y){
		rep(i,0,n){
			if(vis[a[i] - x - y] && a[i] >= x) return cout << "1\n" << a[i] - x << '\n', 0;
			if(vis[a[i] - x + y] && a[i] >= x) return cout << "1\n" << a[i] - x << '\n', 0;
			if(vis[a[i] + x - y] && a[i] <= l - x) return cout << "1\n" << a[i] + x << '\n', 0;
			if(vis[a[i] + x + y] && a[i] <= l - x) return cout << "1\n" << a[i] + x << '\n', 0;
		}
		cout << "2\n" << x << " " << y << '\n';
	}  
	else if(!flag_x) cout << "1\n" << x << '\n';
	else if(!flag_y) cout << "1\n" << y << '\n';
	else cout << "0\n";


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
