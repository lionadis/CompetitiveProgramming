#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;


inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}

template<typename T = int>
inline T nxt(){
    char c=nc();T x=0; int f=1;
    for(;c>'9'||c<'0';c=nc())if(c=='-')f=-1;
    for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc());
    x*=f;
    return x;
}

const int maxn = 200123;
const int lgn = 19;
struct edge{
    int u, v, w, idx;
}e[maxn];

vector<vector<pii> > mst;

int f[lgn][maxn], g[lgn][maxn], tin[maxn], tout[maxn], timer;
ll mst_cost, ans[maxn];

struct UF{
    vi e;
    UF(int n):e(n, -1){};
    bool same_set(int a, int b){return find(a) == find(b);}
    int size(int x) { return -e[find(x)];}
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]);}
    void join(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(e[a] > e[b]) swap(a, b);
        e[a] += e[b], e[b] = a;
    }
};

bool cmp(const edge &a, const edge &b){
    return a.w < b.w;
}

void dfs(int u, int cost = 0, int p = 0){
    f[0][u] = p, g[0][u] = cost;
    tin[u] = timer ++; 
    rep(i,1,lgn){
        f[i][u] = f[i - 1][f[i - 1][u]];
        g[i][u] = max(g[i - 1][u], g[i - 1][f[i - 1][u]]);
    }
    trav(v, mst[u]){
        if(v.F != p) dfs(v.F, v.S, u);
    }
    tout[u] = timer ++;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll solve(int u, int v, int w){
    int max_edge = 0;

    for(int i = lgn - 1; i >= 0; i--){
        if(!is_ancestor(f[i][u], v)){
            max_edge = max(max_edge, g[i][u]);
            u = f[i][u];
        }
    }
    if(!is_ancestor(u, v)) max_edge = max(max_edge, g[0][u]);

    for(int i= lgn - 1; i >= 0; i--){
        if(!is_ancestor(f[i][v], u)){
            max_edge = max(max_edge, g[i][v]);
            v = f[i][v];
        }
    }

    if(!is_ancestor(v, u)) max_edge = max(max_edge, g[0][v]);
    return mst_cost - max_edge + w;
}

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int n = nxt(), m = nxt();
    mst.resize(n);
    rep(i,0,m){
        e[i] = {nxt() - 1, nxt() - 1, nxt(), i};
    }
    sort(e, e + m, cmp);
    UF uf(n);
    int k = n - 1, idx = -1;
    while(k){
        idx ++;
        if(uf.same_set(e[idx].u, e[idx].v)) continue;
        uf.join(e[idx].u, e[idx].v);
        mst[e[idx].u].push_back({e[idx].v, e[idx].w});
        mst[e[idx].v].push_back({e[idx].u, e[idx].w});
        mst_cost += e[idx].w;
        k --;
    }
    dfs(0);
    rep(i,0,m) ans[e[i].idx] = solve(e[i].u, e[i].v, e[i].w);
    rep(i,0,m) cout << ans[i] << '\n';

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}