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
int par[maxn], sz[maxn], d[maxn];
vector<int> G[maxn];

int dfs(int u, int p){
    sz[u] = 1;
    trav(v, G[u])
        if(v != p) sz[u] += dfs(v, u);
    return sz[u];
}

int center(int u){
    trav(v, G[u]){
        if(par[v] == -1 && sz[v] > sz[u] / 2){
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
    d[u] = d[p] + 1;
    par[u] = p;
    trav(v, G[u]){
        if(par[v] == -1) decompose(v, u);
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n;
    cin >> n;
    rep(i, 0, n - 1){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    fill(par, par + n, -1);
    dfs(0, -1);
    decompose(0, -1);
    rep(i, 0, n) cout << (char)(d[i] - 1 + 'A') << ' ' ;
    cout << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}