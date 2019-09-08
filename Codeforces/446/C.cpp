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

const int mod = 1e9 + 9;
const int maxn = 300123;
ll fib[maxn];
vi v;

ll get_fib(int x, int y, int k){
	if(k == 1) return x;
	if(k == 2) return y;
	return x * fib[k - 2] + y * fib[k - 1];
}

struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;
	ll val = 0, x = 0, y = 0;

	Node(vi &v, int lo, int hi):lo(lo), hi(hi){
		if(hi - lo > 1){
			int mid = (lo + hi) / 2;
			l = new Node(v, lo, mid), r = new Node(v, mid, hi);
			val = l->val + r->val, val %=  mod;
		} else val = v[lo];
	}

	void update(int L, int R){
		push();
		if(L >= hi || lo >= R) return;
		if(L <= lo && hi <= R){
			x += get_fib(1, 1, lo - L + 1), x %= mod;
			y += get_fib(1, 1, lo - L + 2), y %= mod;
			push();
			return;
		}
		l->update(L, R), r->update(L, R);
		val = l->val + r->val, val %= mod;
	}
	
	ll query(int L, int R){
		push();
		if(L >= hi || lo >= R) return 0;
		if(L <= lo && hi <= R) return val;
		return (l->query(L, R) + r->query(L, R)) % mod;
	}

	void push(){
		if(!x && !y) return;
		val += get_fib(x, y, hi - lo + 2), val %= mod;
		val += (mod - y), val %= mod;
		if(!l){
			x = y = 0;
			return;
		}
		int mid = (lo + hi) / 2;
		l->x += x, l->x %= mod;
		l->y += y, l->y %= mod;
		r->x += get_fib(x, y, mid - lo + 1), r->x %= mod;
		r->y += get_fib(x, y, mid - lo + 2), r->y %= mod;
		x = y = 0;
	}
};

void build(Node *t, int n){
	rep(i,0,n) cout << t->query(i, i + 1) << " ";
	cout << '\n';
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n, q;
	cin >> n >> q;
	fib[1] = 1;
	rep(i,2,maxn) fib[i] = fib[i - 1] + fib[i - 2], fib[i] %= mod;
	rep(i,0,n){
		int x;
		cin >> x;
		v.push_back(x);
	}
	Node *t = new Node(v, 0, n);
	while(q--){
		int op, l, r;
		cin >> op >> l >> r;
		l--;
		if(op == 1) t->update(l, r);
		else cout << t->query(l, r) << '\n';
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
