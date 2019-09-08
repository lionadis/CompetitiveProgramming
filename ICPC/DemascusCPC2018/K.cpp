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
typedef vector<pii> vpi;
typedef vector<vpi> graph;

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

struct UF{
    vi e;
    UF(int n): e(n, -1){}
    bool same_set(int a, int b){ return find(a) == find(b); }
    int size(int x) { return -e[find(x)];}
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]);}
    void join(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(e[a] > e[b]) swap(a, b);
        e[a] += e[b], e[b] = a;
    }
};


const pii inf(1 << 29, -1);

template<class T>
struct RMQ{
    vector<vector<T>> jmp;

    RMQ(const vector<T> &V){
        int N = sz(V), on = 1, depth = 1;
        while(on < sz(V)) on *= 2, depth++;
        jmp.assign(depth, V);
        rep(i,0,depth-1){
            rep(j,0,N){
                jmp[i+1][j] = min(jmp[i][j], jmp[i][min(N - 1, j + (1 << i))]);
            }
        }
    }

    T query(int a, int b){
        if(b <= a) return inf;
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

struct LCA{
    vi time;
    vector<ll> dist;
    RMQ<pii> rmq;

    LCA(graph& C) : time(sz(C), -99), dist(sz(C)), rmq(dfs(C)) {};

    vpi dfs(graph &C){
        vector<tuple<int, int, int, ll> > q(1);
        vpi ret;
        int T = 0, v, p, d;ll di;
        while(!q.empty()){
            tie(v, p, d, di) = q.back();
            q.pop_back();
            if(d) ret.emplace_back(d, p);
            time[v] = T++;
            dist[v] = di;
            trav(e, C[v]) if(e.first != p)
                    q.emplace_back(e.first, v, d+1, di+e.second);
        }
        return ret;
    }

    int query(int a,int b){
        if(a == b) return a;
        a = time[a], b = time[b];
        return rmq.query(min(a, b), max(a, b)).second;
    }

    ll distance(int a, int b){
        int lca = query(a, b);
        return dist[a] + dist[b] - 2 * dist[lca];
    }
};


int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t = nxt();
    while(t--){
        int n = nxt(), q = nxt(), u_cycle, v_cycle, w_cycle;
        graph G(n);
        UF uf(n);
        rep(i,0,n){
            int u = nxt() - 1, v = nxt() - 1, w = nxt();
            if(uf.same_set(u, v)) {
                u_cycle = u, v_cycle = v, w_cycle = w;
                continue;
            }
            uf.join(u, v);
            G[v].push_back({u, w});
            G[u].push_back({v, w});
        }
        LCA lca(G);
        while(q--){
            int a = nxt() - 1, b = nxt() - 1;
            ll route1 = lca.distance(a, b);
            ll route2 = lca.distance(a, u_cycle) + lca.distance(v_cycle, b) + w_cycle;
            ll route3 = lca.distance(a, v_cycle) + lca.distance(u_cycle, b) + w_cycle;
            cout << min(route1, min(route2, route3)) << '\n';
        }

    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}