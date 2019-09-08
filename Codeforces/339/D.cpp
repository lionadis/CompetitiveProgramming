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

const int maxn = 1 << 18;
int a[maxn], t[maxn], op, n, q;

void merge(int id, int op){
	t[id] = (op ? t[2 * id] | t[2 * id + 1] : t[2 * id] ^ t[2 * id + 1]);
}

void build(int id = 1, int l = 0,int r = n, int op = op){
	if(r - l < 2){
		t[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid, 1 - op);
	build(id * 2 + 1, mid, r, 1 - op);
	merge(id, op);
}

void update(int x, int v, int id = 1, int l = 0, int r = n, int op = op){
	if(r - l < 2){
		t[id] = v;
		return;
	}
	int mid = (l + r) / 2;
	if(x < mid) update(x, v,2 * id, l, mid, 1 - op);
	else update(x, v, 2 * id + 1, mid, r, 1 - op);
	merge(id, op);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	cin >> n >> q;
	op = n % 2;
	n = 1 << n;
	rep(i,0,n) cin >> a[i];
	build();
	while(q--){
		int idx, val;
		cin >> idx >> val;
		idx--;
		update(idx, val);
		cout << t[1] << '\n';
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
