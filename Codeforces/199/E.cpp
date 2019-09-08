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
const int lgn = 17;
int f[lgn][maxn], par[maxn], sz[maxn], d[maxn], tin[maxn], tout[maxn], timer = 0, ans[maxn];
vector<int> G[maxn];

int dfs(int u, int p){
    sz[u] = 1;
    f[0][u] = p;
    d[u] = d[p] + 1;
    tin[u] = timer++;
    rep(i,1,lgn) f[i][u] = f[i - 1][f[i - 1][u]];
    trav(v, G[u]){
        if(v != p) sz[u] += dfs(v, u);
    }
    tout[u] = timer++;
    return sz[u];
}

int is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}


int lca(int u, int v){
    if(is_ancestor(u, v)) return u;
    if(is_ancestor(v, u)) return v;
    for(int i = lgn - 1; i >= 0; --i){
        if(!is_ancestor(f[i][u], v)) u = f[i][u];
    }
    return f[0][u];
}

int dist(int u, int v){
    return d[u] + d[v] - 2 * d[lca(u, v)];
}

int center(int u){
    trav(v, G[u]){
        if(par[v] != -1) continue;
        if(sz[v] > sz[u] / 2){
            sz[u] -= sz[v];
            sz[v] += sz[u];
            return center(v);
        }
    }
    return u;
}

void decompose(int u, int p){
    u = center(u);
    if(p == -1) p = u;
    par[u] = p;
    trav(v, G[u]){
        if(par[v] == -1) decompose(v, u);
    }
}

void update(int u){
    int v = u;
    for(; v != par[v]; v = par[v]) ans[v] = min(ans[v], dist(u, v));
    ans[v] = min(ans[v], dist(u, v));
}

int query(int u){
    int v = u, res = 1e9;
    for(; v != par[v]; v = par[v]) res = min(res, ans[v] + dist(u, v));
    res = min(res, ans[v] + dist(u, v));
    return res;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n, q;
    cin >> n >> q;
    rep(i, 0, n - 1){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    fill(par, par + n, -1);
    fill(ans, ans + n, (int)1e9);
    dfs(0, 0);
    decompose(0, -1);
    update(0);
    while(q--){
        int t, u;
        cin >> t >> u;
        --u;
        if(t == 1) update(u);
        else cout << query(u) << '\n';
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}