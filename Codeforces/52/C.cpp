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

const ll inf = 1e18;
vi v;

struct Node{
	Node *l, *r;
	int lo, hi;
	ll val = inf, m_add = 0;

	Node(vi &v, int lo, int hi):lo(lo), hi(hi){
		if(hi - lo > 1){
			int mid = (lo + hi) / 2;
			l = new Node(v, lo, mid), r = new Node(v, mid, hi);
			val = min(l->val, r->val);
		} else val = v[lo];
	}

	void add(int L, int R, int v){
		if(L >= hi || lo >= R) return;
		if(L <= lo && hi <= R){
			m_add += v;
			val += v;
			return;
		}
		push();
		l->add(L, R, v), r->add(L, R, v);
		val = min(l->val, r->val);
	}

	ll query(int L, int R){
		if(L >= hi || lo >= R) return inf;
		if(L <= lo && hi <= R) return val;
		push();
		return min(l->query(L, R), r->query(L, R));
	}

	void push(){
		if(m_add) l->add(lo, hi, m_add), r->add(lo, hi, m_add), m_add = 0;
	}

};
int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n;
	cin >> n;
	rep(i,0,n){
		int x;
		cin >> x;
		v.push_back(x);	
	}
	Node* t = new Node(v, 0, n);
	int q;
	cin >> q;
	cin.ignore();
	while(q--){
		int a[3], idx = 0;
		string s;
		getline(cin, s);
		stringstream ss(s);
		while(ss >> a[idx++]);
		if(idx == 3){
			if(a[0] > a[1]) cout << min(t->query(a[0], n), t->query(0, a[1] + 1)) << '\n';
			else cout << t->query(a[0], a[1] + 1) << '\n';
		} else {
			if(a[0] > a[1]) t->add(a[0], n, a[2]), t->add(0, a[1] + 1, a[2]);
			else t->add(a[0], a[1] + 1, a[2]);
		}
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
