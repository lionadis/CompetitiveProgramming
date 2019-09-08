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

struct Node{
	Node *l, *r;
	int lo, hi, n4 = 0, n7 = 0, n47 = 0, n74 = 0, rev = 0;
	
	Node (string &s, int lo, int hi):lo(lo), hi(hi){
		if(hi - lo > 1){
			int mid = (lo + hi) / 2;
			l = new Node(s, lo, mid), r = new Node(s, mid, hi);
			merge();
		} else (s[lo] == '4') ? n4 = 1 : n7 = 1;
	}

	void reverse(int L, int R){
		if(L >= hi || lo >= R) return;
		if(L <= lo && hi <= R){
			rev ^= 1;
			swap(n4, n7);
			swap(n47, n74);
			return;
		}
		push();
		l->reverse(L, R), r->reverse(L, R);
		merge();
	}

	int solve(){
		push();
		merge();
		return n47;
	}
	
	void merge(){
		n4 = l->n4 + r->n4;
		n7 = l->n7 + r->n7;
		n47 = max({l->n47 + r->n7, l->n4 + r->n47, l->n4 + r->n7, n4, n7});
		n74 = max({l->n74 + r->n4, l->n7 + r->n74, l->n7 + r->n4, n4, n7});
	}

	void push(){
		if(rev){
			l->reverse(lo, hi), r->reverse(lo, hi);
			rev = 0;
		}
	}

};

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n, q;
	string s;
	cin >> n >> q >> s;
	Node* t = new Node(s, 0, n);
	while(q--){
		string op;
		cin >> op;
		if(op[0] == 's'){
			int l, r;
			cin >> l >> r;
			t->reverse(l - 1, r);
		} else cout << t->solve() << '\n';
		
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
