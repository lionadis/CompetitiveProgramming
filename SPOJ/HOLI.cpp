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
int n, sz[maxn];
ll ans;
vector<vector<pii>> G;

void dfs(int u, int p){
    sz[u] = 1;
    trav(e, G[u]){
        int v = e.F;
        if(v != p){
            dfs(v, u);
            ans += 2ll * e.S * min(n - sz[v], sz[v]);
            sz[u] += sz[v];
        }
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int t;
    cin >> t;
    rep(T, 1, t + 1){
        cin >> n;
        G.clear();
        G.resize(n);
        fill(sz, sz + n, 0);
        ans = 0;
        rep(i,0,n - 1){
            int u, v, w;
            cin >> u >> v >> w;
            --u, --v;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        dfs(0, 0);
        cout << "Case #" << T << ": " << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}