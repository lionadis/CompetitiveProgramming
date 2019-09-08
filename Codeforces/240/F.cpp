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

int n, q;
string s;

static char buf[200 << 20];
void* operator new(size_t s) {
	static size_t i = sizeof buf;
	assert(s < i);
	return (void*)&buf[i -= s];
}
void operator delete(void*) {}

struct Node{
	Node *l = 0, *r = 0;
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
			l->set(lo, hi, m_set), r->set(lo, hi, m_set), m_set = -1;
		}
	}
};

Node *t[30];

void build(){
	rep(i,0,n){
		bool flag = false;
		rep(j,0,26){
			if(t[j]->query(i, i + 1)){
				cout << (char)(j + 'a');
				flag = true;
				break;
			}
		}
		if(!flag) cout << " ";
	}
	cout << '\n';
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	cin >> n >> q >> s;
	rep(i,0,26) t[i] = new Node(0, n);
	rep(i,0,n) t[s[i] - 'a']->set(i, i + 1, 1);
	while(q--){
		int l, r;
		cin >> l >> r;
		l--;
		int cnt[30], odd = 0, c_odd = -1;
		rep(i,0,26){
			cnt[i] = t[i]->query(l, r);
			if(cnt[i] % 2){
				odd += cnt[i] % 2;
				c_odd = i;
			}
		}
		if(!odd || (odd == 1 && (r - l) % 2)){
			rep(i,0,26) t[i]->set(l, r, 0);
			if(odd) t[c_odd]->set((r + l) / 2, (r + l) / 2 + 1, 1), cnt[c_odd]--;
			int curr = l;
			rep(i,0,26){
				if(!cnt[i]) continue;
				t[i]->set(curr, curr + cnt[i] / 2, 1);
				t[i]->set(r - (curr - l) - cnt[i] / 2, r - (curr - l), 1);
				curr += cnt[i] / 2;
			}
		}
	}
	build();
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
