#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

using ll = long long;
using pli = pair<ll, int>;
using vi = vector<int>;

const int maxn = 1000123, mod = (int) 1e9 + 7;
int phi[maxn];
vi v;

ll binpow(ll x, int p){
	ll a = 1, b = x;
	while(p){
		if(p&1) a *= b, a %= mod;
		b *= b;
		b %= mod;
		p >>= 1;
	}
	return a;
}

struct Node{
	Node *l = 0, *r = 0;
	int lo, hi;
	pli ans;
	
	Node(vi &v, int lo, int hi):lo(lo), hi(hi){
		if(hi - lo > 1){
			int mid = (lo + hi) / 2;
			l = new Node(v, lo, mid), r = new Node(v, mid, hi);
			ans = f(l->ans, r->ans);
		}
		else ans = {phi[v[lo]], v[lo]};
	}

	pli query(int L, int R){
		if(L >= hi || lo >= R) return {1LL, 0};
		if(L <= lo && hi <= R) return ans;
		return f(l->query(L, R), r->query(L, R));
	}

	pli f(pli a, pli b){
		if(a.S == 0) return b;
		if(b.S == 0) return a;
		pli res;
		res.S = __gcd(a.S, b.S);
		res.F = a.F * b.F;
		res.F %= mod;
		res.F *= res.S;
		res.F %= mod;
		res.F *= binpow(phi[res.S], mod - 2);
		res.F %= mod;
		return res;
	}
};

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	phi[0] = 1;
	rep(i,1,maxn) phi[i] = i;
	rep(i,2,maxn){
		if(phi[i] == i){
			for(int j = i; j < maxn; j += i) phi[j] *= (i - 1), phi[j] /= i;
		}
	}
	int n;
	cin >> n;
	v.resize(n);
	rep(i,0,n) cin >> v[i];
	Node *t = new Node(v, 0, n);
	int q;
	cin >> q;
	/*
	rep(i,0,n) cout << (t->query(i, i + 1)).F << " ";
	cout << '\n';
	*/
	while(q--){
		int l, r;
		cin >> l >> r;
		l--;
		cout << (t->query(l ,r)).F << " " << (t->query(l, r)).S << '\n';
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
