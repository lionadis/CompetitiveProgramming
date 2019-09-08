#include <bits/stdc++.h>
//Getting WA ??
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
	int val, y, c = 1;
	Node(int val) : val(val), y(rand()) {}
	void recalc();
};

int cnt(Node* n) { return n ? n->c : 0; }
void Node::recalc() { c = cnt(l) + cnt(r) + 1; }

template<class F> void each(Node* n, F f) {
	if (n) { each(n->l, f); f(n->val); each(n->r, f); }
}

pair<Node*, Node*> split_by_val(Node* n, int v) {
	if (!n) return {};
	if (n->val >= v) { // "n->val >= v" for lower_bound(v)
		auto pa = split_by_val(n->l, v);
		n->l = pa.second;
		n->recalc();
		return {pa.first, n};
	} else {
		auto pa = split_by_val(n->r, v);
		n->r = pa.first;
		n->recalc();
		return {n, pa.second};
	}
}

pair<Node*, Node*> split_by_idx(Node* n, int k) {
	if (!n) return {};
	if (cnt(n->l) >= k) { // "n->val >= v" for lower_bound(v)
		auto pa = split_by_idx(n->l, k);
		n->l = pa.second;
		n->recalc();
		return {pa.first, n};
	} else {
		auto pa = split_by_idx(n->r, k - cnt(n->l) - 1);
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

Node* ins(Node* t, int x){
    Node *a, *b, *c;
    tie(a, b) = split_by_val(t, x), tie(b, c) = split_by_val(b, x+1);
    return merge(a, merge(new Node(x), c));
}

Node* del(Node *t, int x){
    Node *a, *b, *c;
    tie(a, b) = split_by_val(t, x), tie(b, c) = split_by_val(b, x+1);
    return merge(a, c);
}

int index_of(Node* &t, int x){
    Node *a, *b, *c;
    tie(a, b) = split_by_val(t, x), tie(b, c) = split_by_val(b, x+1);
    int ans = (cnt(b) ? cnt(a) + 1: -1);
    t = merge(a, merge(b, c));
    return ans;
}

int kth(Node* &t, int k){
    if(cnt(t) < k) return -1;
    k--;
    Node *a, *b, *c;
    tie(a, b) = split_by_idx(t, k), tie(b, c) = split_by_idx(b, 1);
    int ans = b->val;
    t = merge(a, merge(b, c));
    return ans;
}

void output(Node *t){
    if(!t) return;
    output(t->l);
    cout << t->val << " ";
    output(t->r);
}

int main(){
#ifndef ONLINE_JUDGE
    f_in
#else
    _
#endif
    srand(time(NULL));
    Node* t = NULL;
    int op = nxt();
    while(~op){
        int x = nxt();
        if(op == 1) t = ins(t, x);
        if(op == 2) t = del(t, x);
        if(op == 3) cout << index_of(t, x) << '\n';
        if(op == 4) cout << kth(t, x) << '\n';
        op = nxt();
    }
}
