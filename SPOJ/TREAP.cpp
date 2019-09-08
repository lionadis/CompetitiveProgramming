#include <bits/stdc++.h>
//Got 95
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
#define int ll

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

const int MOD = (int)2e16;

struct Node {
	Node *l = 0, *r = 0;
	int val, y, c = 1, max_v = 0, min_v = 0, min_diff = MOD;
	Node(int val) : val(val), y(rand()), max_v(val), min_v(val) {}
	void recalc();
};


int cnt(Node* n) { return n ? n->c : 0; }
int get_min(Node *n){ return n ? n->min_v : MOD;}
int get_max(Node *n){ return n ? n->max_v : -MOD;}
int get_diff(Node *n){ return n ? n->min_diff : MOD;}

void Node::recalc() {
    c = cnt(l) + cnt(r) + 1;
    max_v = max(val, max(get_max(l), get_max(r)));
    min_v = min(val, min(get_min(l), get_min(r)));
    min_diff = MOD;
    if(l) min_diff = min(min_diff, min(get_diff(l), abs(val - get_max(l))));
    if(r) min_diff = min(min_diff, min(get_diff(r), get_min(r) - val));
}

template<class F> void each(Node* n, F f) {
	if (n) { each(n->l, f); f(n->val); each(n->r, f); }
}

pair<Node*, Node*> split(Node* n, int k) {
	if (!n) return {};
	if (cnt(n->l) >= k) { // "n->val >= v" for lower_bound(v)
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

Node* ins(Node *t, int val){
    auto a = split_by_val(t, val);
    auto b = split_by_val(a.S, val+1);
    return merge(a.F, merge(new Node(val), b.S));
}

Node* del(Node *t, int val){
    auto a = split_by_val(t, val);
    auto b = split_by_val(a.S, val+1);
    return merge(a.F, b.S);
}

int val(Node* &t, int idx){
    auto a = split(t, idx);
    auto b = split(a.S, 1);
    int ans = (b.F)->val;
    t = merge(a.F, merge(b.F, b.S));
    return ans;
}

template<class F>
int query(Node* &t, int l, int r, F f){
    auto a = split(t, r+1);
    auto b = split(a.F, l);
    int ans = f(b.S);
    t = merge(merge(b.F, b.S), a.S);
    return ans;
}


main(){
#ifndef ONLINE_JUDGE
    f_in
#else
    _
#endif
    int n;
    cin >> n;
    Node *t = NULL;
    while(n--){
        char op;
        cin >> op;
        if(op == 'I'){
            int x;
            cin >> x;
            t = ins(t, x);
        }
        if(op == 'D'){
            int x;
            cin >> x;
            t = del(t, x);
        }
        if(op == 'N'){
            int l, r;
            cin >> l >> r;
            if(r-l < 1) cout << "-1\n";
            else {
                int ans = query(t, l, r, get_diff);
                cout << (ans <= 0 || ans > (ll)2e15 ? -1 : ans) << '\n';
            }
        }
        if(op == 'X'){
            int l, r;
            cin >> l >> r;
            if(r-l < 1) cout << "-1\n";
            else {
                int ans = query(t, l, r, get_max) - query(t, l, r, get_min);
                cout << (ans <= 0 || ans > (ll)2e15 ? -1 : ans) << '\n';
            }
        }
    }
}
