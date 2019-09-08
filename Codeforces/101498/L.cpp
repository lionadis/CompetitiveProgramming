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

const int maxn = 2012;
const int inf = 2e9 + 123;
int dist[maxn];
bool vis[maxn], flag;
vector<vector<pii> > G;

void spfa(int u){
	if(flag) return;
	vis[u] = true;
	trav(p, G[u]){
		int v = p.F, w = p.S;
		if(dist[v] > dist[u] + w){
			if(vis[v]){
				flag = true;
				break;
			}
			dist[v] = dist[u] + w;
			spfa(v);
		}
	}
	vis[u] = false;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		flag = false;
		G.clear();
		G.resize(n + 1);
		fill(vis, vis + n + 1, false);
		fill(dist, dist + n + 1, inf);
		int ans = inf;
		rep(i,0,m){
			int u, v, w;
			cin >> u >> v >> w;
			G[u].push_back({v, w});
			ans = min(ans, w);
		}
		if(ans >= 0){
			cout << ans << '\n';
			continue;
		}
		rep(i,1,n + 1) G[0].push_back({i, 0});
		dist[0] = 0;
		spfa(0);
		rep(i,1,n + 1) ans = min(ans, dist[i]);
		if(flag) cout << "-inf\n";
		else cout << ans << '\n';
	}

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
