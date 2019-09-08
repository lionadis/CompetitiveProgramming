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

const int maxn = 100213;
int a[maxn], n;
struct node{
	int v, cnt;
}t[4 * maxn];

node merge(node a, node b){
	int g = __gcd(a.v, b.v);
	node res = {g, 0};
	if(a.v == g) res.cnt += a.cnt;
	if(b.v == g) res.cnt += b.cnt;
	return res;
}

void build(int id = 1, int l = 0, int r = n){
	if(r - l < 2){
		t[id] = {a[l], 1};
		return;
	}
	int mid = (l + r) / 2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	t[id] = merge(t[2 * id], t[2 * id + 1]);
}

node query(int L, int R, int id = 1, int l = 0, int r = n){
	if(L >= r || R <= l) return {0, 0};
	if(L <= l && R >= r) return t[id];
	int mid = (l + r) / 2;
	return merge(query(L, R, 2 * id, l, mid), query(L, R, 2 * id + 1, mid, r));
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	cin >> n;
	rep(i,0,n) cin >> a[i];
	build();
	int q;
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		--l;
		cout << r - l -  query(l, r).cnt << '\n';
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
