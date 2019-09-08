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

const int maxn = 1234;
bool a[maxn], b[maxn], vis[maxn];
vector<vi> G;

int main() {
#ifdef LOCAL_DEFINE
   // freopen("test.in","r",stdin);
#else
   // cin.sync_with_stdio(0); cin.tie(0);
#endif
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		G.clear();
		G.resize(n);
		fill(a, a + maxn, false);
		fill(b, b + maxn, false);
		fill(vis, vis + maxn, false);
		rep(i,0,n - 1){
			int u, v;
			cin >> u >> v;
			u--, v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int k1, k2, y1;
		cin >> k1;
		rep(i,0,k1){
			int x;
			cin >> x;
			a[x - 1] = true;
		}
		cin >> k2;
		rep(i,0,k2){
			int x;
			cin >> x;
			y1 = x;
			b[x - 1] = true;
		}
		cout << "B " << y1 << '\n';
		cout.flush();
		int x1;
		cin >> x1;
		queue<int> Q;
		Q.push(x1 - 1);
		while(!Q.empty()){
			int u = Q.front();Q.pop();
			if(a[u]){
				x1 = u + 1;
				break;
			}
			vis[u] = true;
			trav(v, G[u]) if(!vis[v]) Q.push(v);
		}
		cout << "A " << x1 << '\n';
		cout.flush();
		cin >> y1;
		cout << "C " << (b[y1 - 1] ? x1:-1) << '\n';
		cout.flush();
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
