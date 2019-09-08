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

const int maxn = 200123;
int t[4 * maxn], a[maxn], n, x;

void build(int id = 1, int l = 0, int r = n){
	if(r - l <= 1){
		t[id] = 1;
		return;
	}
	int mid = (l + r) / 2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid, r);
	t[id] = t[2 * id] + t[2 * id + 1];
}

int query(int L, int R, int id = 1, int l = 0, int r = n){
	if(L >= r || R <= l) return 0;
	if(L <= l && R >= r) return t[id];
	int mid = (l + r) / 2;
	return query(L, R, 2 * id, l, mid)
		 + query(L, R, 2 * id + 1, mid, r);
}

int upper_bound(int v, int id = 1, int l = 0, int r = n){
	if(r - l <= 1){
		return l;
	}
	int mid = (l + r) / 2;
	if(t[2 * id] > v) return upper_bound(v, 2 * id, l, mid);
	return upper_bound(v - t[2 * id], 2 * id + 1, mid, r);
}

void update(int x, int v, int id = 1, int l = 0, int r = n){
	if(x < l || x >= r) return;
	if(r - l <= 1){
		if(l == x){
			t[id] += v;
			return;
		}
	}
	int mid = (l + r) / 2;
	update(x, v, 2 * id, l, mid);
	update(x, v, 2 * id + 1, mid, r);
	t[id] = t[2 * id] + t[2 * id + 1];
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	cin >> n;
	build();
	rep(i,0,n) cin >> x, a[i] = query(0, x), update(x, -1);
	build();
	rep(i,0,n) cin >> x, a[i] += query(0, x), update(x, -1);
	for(int i = n - 2;i >= 0; --i) a[i] += a[i + 1] / (n - i - 1), a[i + 1] %= (n - i - 1);
	a[0] %= n;
	build();
	rep(i,0,n){
		int x = upper_bound(a[i]);
		update(x, -1);
		cout << x << " ";
	}
	cout << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
