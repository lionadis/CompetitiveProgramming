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

unordered_map<int, int> p, x;

int find(int u){
	auto it = p.find(u);
	if(it == p.end()){
		x[u] = 0;
		return u;
	}
	int v = it->S, vv = find(v);
	x[u] ^= x[v];
	return p[u] = vv;
}

void unite(int u, int v, int val){
	int a = find(u), b = find(v);
	if(a == b) return;
	p[a] = b;
	x[a] = x[u] ^ x[v] ^ val;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int q, last = 0;
	cin >> q;
	while(q--){
		int t, l, r;
		cin >> t >> l >> r;
		l ^= last, r ^= last;
		if(l > r) swap(l, r);
		r++;
		if(t == 1){
			int val; cin >> val;
			val ^= last;
			unite(l ,r, val);
		} else {
			int a = find(l), b = find(r);
			if(a != b) last = -1;
			else last = x[l] ^ x[r];
			cout << last << '\n';
			last = abs(last);
		}
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
