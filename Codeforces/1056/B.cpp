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

const int maxn = 1023;
ll cnt[maxn], cnt2[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n, m;
	cin >> n >> m;
	rep(i,0,m){
		cnt[i] = n / m;
		if(i <= n % m) cnt[i] ++;
	}
	ll ans = 0;
	cnt[0]--;
	rep(i,0,m) cnt2[(i * i) % m] += cnt[i];
	cnt2[m] = cnt2[0];
	rep(i,0,m) ans += cnt2[i] * cnt2[(m - i)];
	cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
