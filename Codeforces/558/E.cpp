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

struct Node {
	Node *l = 0 ,*r = 0;
	int lo, hi, val = 0, m_set = -1;

	Node (int lo, int hi):lo(lo), hi(hi){};

	void set(int L, int R, int v){
		if(L >= hi || lo >= R) return;
		if(L <= lo && hi <= R){
			val = (hi - lo) * v;
			m_set = v;
			return;
		}
		push();
		l->set(L, R, v), r->set(L, R, v);
		val = l->val + r->val;
	}

	int query(int L, int R){
		if(L >= hi || lo >= R) return 0;
		if(L <= lo && hi <= R) return val;
		push();
		return l->query(L, R) + r->query(L, R);
	}

	void push(){
		if(!l){
			int mid = (lo + hi) / 2;
			l = new Node(lo, mid), r = new Node(mid, hi);
		}
		if(~m_set){
			l->set(lo, hi, m_set), r->set(lo, hi, m_set);
			m_set = -1;
		}
	}
};

Node* t[26];

void build(int n){
	rep(i,0,n){
		rep(j,0,26)
			if(t[j]->query(i, i + 1)){
				cout << (char)(j + 'a');
				break;
			}
	}
	cout << '\n';
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n, q;
	string s;
	cin >> n >> q >> s;
	rep(i,0,26) t[i] = new Node(0, n);
	rep(i,0,n) t[s[i] - 'a']->set(i, i + 1, 1);
	while(q--){
		int l, r, k;
		cin >> l >> r >> k;
		l--;
		if(k){
			int curr = l;
			rep(i,0,26){
				int cnt = t[i]->query(l ,r);
				t[i]->set(l, r, 0);
				t[i]->set(curr, curr + cnt, 1);
				curr += cnt;
			}
		} else {
			int curr = l;
			for(int i=25;i>=0;--i){
				int cnt = t[i]->query(l, r);
				t[i]->set(l, r, 0);
				t[i]->set(curr, curr + cnt, 1);
				curr += cnt;
			}
		}
	}
	build(n);
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
