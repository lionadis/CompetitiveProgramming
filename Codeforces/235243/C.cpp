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
const int maxk = 70;
int t[maxk][5 *  maxn][2], sz[maxk], cnt[maxk];
ll a[maxn], ans[maxk];

void insert(ll x, int block){
	cnt[block]++;
	int now = 1;
	for(int k = 20;~k;k--){
		if(!t[block][now][(x >> k) & 1]) t[block][now][(x >> k) & 1] = ++sz[block];
		now = t[block][now][(x >> k) & 1];
	}
}

ll query(ll x, int block){
	if(cnt[block] == 0) return -1;
	int res = 0, now = 1;
	for(int k = 20;~k;k--){
		if(t[block][now][!((x >> k) & 1)]) res |= 1LL << k, now = t[block][now][!((x >> k) & 1)];
		else now = t[block][now][(x >> k) & 1];
	}
	return res;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	memset(ans, -1, sizeof ans);
	fill(sz, sz + maxk, 1);
	int n, q;
	cin >> n >> q;
	rep(i,0,n){
		cin >> a[i];
		rep(k,0,21){
			insert(a[i], 2 * k + ((a[i] >> k) & 1));
		}
	}
	rep(i,0,n){
		rep(k,0,21){
			ans[k] = max(ans[k], query(a[i], 2 * k + ((a[i] >> k) & 1)));
		}
	}
	rep(i,21,64) ans[i] = *max_element(ans, ans + 32);
	while(q--){
		ll x, k = 0;
		cin >> x;
		k = log2(x);
		cout << ans[k] << '\n';
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
