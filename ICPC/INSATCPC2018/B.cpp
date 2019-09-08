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
int a[maxn], fib[2 * maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n, q;
	cin >> n >> q;
	int x = 0, y = 1;
	while(x <= maxn){
		int c = y;
		y += x;
		x = c;
		fib[x] = 1;
	}
	rep(i,0,n) cin >> a[i];
	rep(i,0,q){
		int op, l, r;
		cin >> op >> l >> r;
		if(op == 1) rep(i,l - 1,r) a[i]++;
		else{
			int ans = 0;
			rep(i,l - 1,r) ans += fib[a[i]];
			cout << ans << '\n';
		}
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
