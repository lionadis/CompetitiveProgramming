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

const int maxn = 300123;
int x[maxn], y[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n, max_x = -1e8, min_x = 1e8, max_y = -1e8, min_y = 1e8;
	cin >> n;
	rep(i,0,n){
		cin >> x[i] >> y[i];
		max_x = max(x[i], max_x);
		min_x = min(x[i], min_x);
		max_y = max(y[i], max_y);
		min_y = min(y[i], min_y);
	}
	ll max_rect = 2ll * (max_x - min_x + max_y - min_y), rect_3 = 0;
	rep(i,0,n){
		int h = max(y[i] - min_y, max_y - y[i]);
		int w = max(x[i] - min_x, max_x - x[i]);
		rect_3 = max(rect_3, 2ll * (h + w));
	}
	cout << rect_3 << " ";
	rep(i,4,n + 1) cout << max_rect << " ";
	cout << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
