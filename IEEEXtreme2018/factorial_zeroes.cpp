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

int cnt[123][123];

ll count(ll x, int b){
	ll ans = 1e18;
	rep(i,2,100){
		ll curr_cnt = 0;
		if(cnt[b][i]){
			int p = i;
			while(x >= p){
				curr_cnt += x / p;
				p *= i;
			}

		}
		ans = min(curr_cnt / cnt[b][i], ans);
	}
	return ans;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int t;
	cin >> t;
	rep(i,2,101){
		int x = i, p = 2;
		while(x != 1){
			while(x % p == 0) x /= p, cnt[i][p]++;
			p++;
		}
	}
	cout << count(6, 10) << '\n';
	/*
	while(t--){
		ll b, n;
		cin >> b >> n;
		ll l = 1, r = 1e18;
		while(l < r){
			ll mid = (l + r + 1) / 2;
			if(cnt(mid, a[b]) < n) l = mid;
			else r = mid - 1;
		}
		l++;
		cout << l << " " << cnt(l, a[b]) << '\n';
		cout << (cnt(l, a[b]) == n ? l : - 1) << '\n';
	}
	*/
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
