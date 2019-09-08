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

const int maxn = 300123;
int t[4 * maxn], a[maxn], n, m;

void build(int id = 1, int l = 0, int r = n){
	if(r - l < 2){
		t[id] = 1;
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	t[id] = t[2 * id] + t[2 * id + 1];
}

void update(int l, int r, int x, int id = 1, int L = 0, int R = n){
	if(r <= L || R <= l) return;
	if(t[id] == 0) return;
	if(R - L < 2){
		if(L != x) t[id] = 0, a[L] = x + 1;
		return;
	}
	int mid = (L + R) / 2;
	update(l, r, x, id * 2, L, mid);
	update(l, r ,x, id * 2 + 1, mid, R);
	t[id] = t[2 * id] + t[2 * id + 1];
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	cin >> n >> m;
	build();
	while(m--){
		int l, r, x;
		cin >> l >> r >> x;
		--l, --x;
		update(l, r, x);
	}
	rep(i,0,n) cout << a[i] << " ";
	cout << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
