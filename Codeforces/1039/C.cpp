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

const int maxn = 500123;
const int mod = 1e9 + 7;
int f[maxn], size[maxn];
ll a[maxn];

struct edge {
	int u, v;
	ll cost;
} E[maxn];

int find(int u){
	return (f[u] == u ? u:f[u] = find(f[u]));
}

void unite(int u, int v){
	u = find(u), v = find(v);
	if(u == v) return;
	if(size[u] < size[v]) swap(u, v);
	f[v] = u;
	size[u] += size[v];
}

ll binpow(int x, int y){
	ll b = x, a = 1;
	while(y){
		if(y&1) a *= b, a %= mod;
		b *= b;
		b %= mod;
		y /= 2;
	}
	return a;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n, m, k, s = 1;
	cin >> n >> m >> k;
	rep(i,0,n) cin >> a[i], s *= 2, s %= mod, f[i] = i, size[i] = 1;
	rep(i,0,m){
		int u, v;
		cin >> u >> v;
		--u, --v;
		E[i] = {u, v, a[u] ^ a[v]};
	}
	sort(E, E + m, [&](edge &a, edge &b){
			return a.cost < b.cost;
		}
	);
	ll ans = s * ((1LL << k) % mod);
	ans %= mod;
	rep(l,0,m){
		int cnt = n, r = l;
		while(E[l].cost == E[r].cost && r < m){
			r++;
			if(find(E[r - 1].u) == find(E[r - 1].v)) continue;
			unite(E[r - 1].u, E[r - 1].v);
			cnt--;
		}
		ans -= s, ans += mod, ans %= mod;
		ans += binpow(2, cnt), ans %= mod;
		rep(i,l,r){
			f[E[i].u] = E[i].u;
			f[E[i].v] = E[i].v;
		}
		l = r - 1;
	}
	cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
