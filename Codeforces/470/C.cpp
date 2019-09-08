#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define f_in freopen("test.in","r",stdin);
#define f_out freopen("test.in","w",stdout);
#define debug(x) cerr << #x << " : " << x << "\n";
#define _ cin.sync_with_stdio(0); cin.tie(0);
#define tl cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n"
#define Func {ans += solve(i); ++i;}


typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}

template<typename T = int>
inline T nxt(){
    char c=nc();T x=0; int f=1;
    for(;c>'9'||c<'0';c=nc())if(c=='-')f=-1;
    for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc());
    x*=f;
    return x;
}

struct Node {
	Node *l = 0, *r = 0;
	ll val = 0, y = 0, c = 1, lazy = 0, sum = 0;
	Node(ll val) : val(val), y(rand()), sum(val) {}
	void recalc();
};

int cnt(Node* n) { return n ? n->c : 0; }
ll get_sum(Node* n) { return n ? n->sum : 0; }
void Node::recalc() { sum = get_sum(l)+ get_sum(r) + val,  c = cnt(l) + cnt(r) + 1; }

pair<Node*, Node*> split(Node* n, ll v) {
	if (!n) return {};
	if (n->val >= v) { // "n->val >= v" for lower_bound(v)
		auto pa = split(n->l, v);
		n->l = pa.second;
		n->recalc();
		return {pa.first, n};
	} else {
		auto pa = split(n->r, v);
		n->r = pa.first;
		n->recalc();
		return {n, pa.second};
	}
}

Node* merge(Node* l, Node* r) {
	if (!l) return r;
	if (!r) return l;
	if (l->y > r->y) {
		l->r = merge(l->r, r);
		l->recalc();
		return l;
	} else {
		r->l = merge(l, r->l);
		r->recalc();
		return r;
	}
}

Node *ins(Node *t, ll v){
    Node *a, *b;
    tie(a, b) = split(t, v);
    return merge(merge(a, new Node(v)), b);
}

void output(Node *t){
    if(t){
        output(t->l);
        cout << t->val << ' ';
        output(t->r);
    }
}

const int N = 100010;
ll a[N], t[N], offset = 0;

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    Node *treap = NULL;
    int n = nxt();
    rep(i,0,n) a[i] = nxt();
    rep(i,0,n) t[i] = nxt();
    rep(i,0,n){
        treap = ins(treap, offset + a[i]);
        ll ans = 0;
        Node *a;
        tie(a, treap) = split(treap, offset + t[i]);
        ans += t[i] * cnt(treap);
        ans += get_sum(a) - offset * cnt(a);
        offset += t[i];
        cout << ans << " ";
    }
}