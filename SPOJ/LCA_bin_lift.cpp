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

const int maxn = 100123, lgn = 20;
int f[lgn][maxn], tin[maxn], tout[maxn], timer = 0;

vector<vi> G;

void dfs(int u, int p = 0){
    f[0][u] = p;
    rep(i,1,lgn) f[i][u] = f[i - 1][f[i - 1][u]];
    tin[u] = ++timer;
    trav(v, G[u])
        if(v != p) dfs(v, u);
    tout[u] = ++timer;
}

bool is_anc(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if(is_anc(u, v)) return u;
    if(is_anc(v, u)) return v;
    for(int i=lgn-1;i>=0;--i){
        if(!is_anc(f[i][u], v)) u = f[i][u];
    }
    return f[0][u];
}


int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t = nxt();
    rep(T,1,t+1){
        cout << "Case " << T << ": " << '\n';
        timer = 0;
        int n = nxt();
        G.clear(), G.resize(n);
        rep(i,0,n){
            int x = nxt();
            rep(j,0,x){
                int v = nxt() - 1;
                G[i].push_back(v);
                G[v].push_back(i);
            }
        }
        dfs(0);
        int q = nxt();
        while(q--){
            int u = nxt() - 1, v = nxt() - 1;
            cout << lca(u, v) + 1<< '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}