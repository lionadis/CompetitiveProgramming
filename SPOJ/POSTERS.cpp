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

const int maxn = 40123, inf = 1e7 + 123, lgn = 30;
int L_node[2 * maxn * lgn], R_node[2 * maxn * lgn], lazy[2 * maxn * lgn], sz = 1;
set<int> ans;

void init(){
	sz = 1;
	ans.clear();
	memset(L_node, 0, sizeof L_node);
	memset(R_node, 0, sizeof R_node);
	memset(lazy, -1, sizeof lazy);
}

int create(int &id){
	if(!id) id = ++sz;
	return id;
}

void push(int id){
	if(!L_node[id]) create(L_node[id]), create(R_node[id]);
	if(~lazy[id])
		lazy[L_node[id]] =  lazy[R_node[id]] = lazy[id];
	lazy[id] = -1;
}
		

void update(int l, int r, int v, int id = 1, int L = 0, int R = inf){
	if(r <= L || R <= l) return;
	if(l <= L && R <= r){
		lazy[id] = v;
		return;
	}
	push(id);
	int mid = (L + R) / 2;
	update(l, r, v, L_node[id], L, mid);
	update(l, r, v, R_node[id], mid, R);
}

void solve(int id = 1, int L = 0, int R = inf){
	if(!id) return;
	if(~lazy[id]){
		ans.insert(lazy[id]);
		return;
	}
	int mid = (L + R) / 2;
	solve(L_node[id], L, mid);
	solve(R_node[id], mid, R);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int t;
	cin >> t;
	rep(T,1,t + 1){
		int q;
		cin >> q;
		init();
		while(q--){
			int l, r;
			cin >> l >> r;
			l--;
			update(l, r, q);
		}
		solve();
		cout << "Case " << T << ": "<< sz(ans) << '\n';
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
