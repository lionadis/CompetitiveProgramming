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

const int maxn = 100123;
int t[4 * maxn], a[maxn], b[maxn], x[maxn], y[maxn], n, q;	

void update(int L, int R, int v, int id = 1, int l = 0, int r = n){
	if(R <= l || L >= r) return;
	if(L <= l && R >= r){
		t[id] = v;
		return;
	}
	int mid = (l + r) / 2;
	update(L, R, v, 2 * id, l, mid);
	update(L, R, v, 2 * id + 1, mid, r);
}

int query(int L, int R, int id = 1, int l = 0, int r = n){
	if(R <= l || L >= r) return -1;
	if(L <= l && R >= r) return t[id];
	int mid = (l + r) / 2;
	int ans =  max(query(L, R, 2 * id, l, mid), query(L, R, 2 * id + 1, mid, r));  
	return ans = max(ans, t[id]);
}

void print(int id = 1, int l = 0, int r = n){
	if(r - l < 2){
		cout << t[l] << " ";
		return;
	}
	int mid = (l + r) / 2;
	print(2 * id, l, mid);
	print(2 * id + 1, mid, r);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	cin >> n >> q;
	rep(i,0,n) cin >> a[i];
	rep(i,0,n) cin >> b[i];
	fill(t, t + 4 * n, -1);
	rep(i,0,q){
		int op;
		cin >> op;
		if(op == 1){
			int k;
			cin >> x[i] >> y[i] >> k;
			x[i]--, y[i]--;
			update(y[i], y[i] + k, i);
		}
		else {
			int idx;
			cin >> idx;
			idx--;
			int k = query(idx, idx + 1);
			if(k == -1) cout << b[idx] << '\n';
			else cout << a[idx + x[k] - y[k]] << '\n';
		}
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
