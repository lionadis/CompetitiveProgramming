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
int n, m, s, t, ord[maxn], p[maxn], path[maxn], len, nxt;
vector<vi> G;
vi ans;

void dfs(int u){
    if(u == t) return;
    trav(v, G[u]){
        if(p[v] == -1) p[v] = u, dfs(v);
    }
}

int calc(int u){
    if(ord[u]){
        nxt = max(nxt, ord[u]);
        return ord[u];
    }
    ord[u] = -1;
    trav(v, G[u]){
        ord[u] = max(ord[u], calc(v));
    }
    return ord[u];
}

void dfs2(int u){
    trav(v, G[u]) calc(v);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    freopen("assassination.in","r",stdin);
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    cin >> n >> m >> s >> t;
    s--, t--;
    G.resize(n);
    rep(i,0,m){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
    }
    memset(p, -1, sizeof p);
    p[s] = s;
    dfs(s);
    while(p[t] != t){
        path[len++] = t;
        t = p[t];
    }
    path[len++] = s;
    reverse(path, path + len);
    rep(i,0,len) ord[path[i]] = i + 1;
    dfs2(s);
    rep(i, 1, len - 1){
        if(nxt == i + 1) ans.push_back(path[i]);
        dfs2(path[i]);
    }
    sort(all(ans));
    cout << sz(ans) << '\n';
    trav(u, ans) cout << u + 1 << " ";
    cout << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}