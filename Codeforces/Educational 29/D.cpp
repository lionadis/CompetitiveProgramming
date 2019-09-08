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
    for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc()); x*=f;
    return x;
}

struct Node {
	Node *l = 0, *r = 0;
	int val, y, c = 1, rev = 0;
	Node(int val) : val(val), y(rand()) {}
	void recalc();
};

int cnt(Node* n) { return n ? n->c : 0; }
void Node::recalc() { c = cnt(l) + cnt(r) + 1; }
void push(Node* n){
    if(n && n->rev){
        n->rev = 0;
        swap(n->l, n->r);
        if(n->l) n->l->rev ^= 1;
        if(n->r) n->r->rev ^= 1;
    }
}
template<class F> void each(Node* n, F f) {
	if (n) { each(n->l, f); f(n->val); each(n->r, f); }
}

pair<Node*, Node*> split(Node* n, int k) {
	if (!n) return {};
    push(n);
	if (cnt(n->l) >= k) {
		auto pa = split(n->l, k);
		n->l = pa.second;
		n->recalc();
		return {pa.first, n};
	} else {
		auto pa = split(n->r, k - cnt(n->l) - 1);
		n->r = pa.first;
		n->recalc();
		return {n, pa.second};
	}
}

Node* merge(Node* l, Node* r) {
	push(l), push(r);
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

Node* ins(Node *t, int val){
    return merge(t, new Node(val));

}

pair<Node*, int> val(Node *t, int idx){
    Node *a, *b, *c;
    tie(a, b) = split(t, idx);
    tie(b, c) = split(b, 1);
    int ans = b->val;
    b = merge(b, c);
    t = merge(a, b);
    return {t, ans};
}

Node* reverse(Node *t, int l, int r){
    Node *a, *b, *c;
    tie(b,c) = split(t, r+1), tie(a,b) = split(b, l);
    b->rev ^= 1;
    b = merge(a, b);
    t = merge(b, c);
    return t;
}

Node* cyclic_shift(Node *t, int l, int r){
    Node *a, *b, *c, *last;
    tie(b, c) = split(t, r), tie(a, b) = split(b, l), tie(last, c) = split(c, 1);
    a = merge(a, last);
    b = merge(b, c);
    t = merge(a, b);
    return t;
}

void output(Node *t){
    rep(i,0,cnt(t)){
        int x;
        tie(t, x) = val(t, i);
        cout << x << " ";
    }
    cout << '\n';
}

int main(){
#ifndef ONLINE_JUDGE
    f_in
#else
    _
#endif
    Node *t = NULL;
    int n = nxt(), q = nxt(), m = nxt();
    rep(i,0,n) t = ins(t, nxt());
    while(q--){
        int op = nxt(), l = nxt() - 1, r = nxt() - 1;
        if(op == 1) t = cyclic_shift(t, l, r);
        if(op == 2) t = reverse(t, l, r);
    }
    while(m--){
        int ans;
        tie(t, ans) = val(t, nxt()-1);
        cout << ans << " ";
    }
    cout << '\n';
}
