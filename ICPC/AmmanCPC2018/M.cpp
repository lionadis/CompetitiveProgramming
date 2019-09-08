#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define f_in freopen("test.in","r",stdin);
#define f_out freopen("test.in","w",stdout);
#define dbg(x) cerr << #x << " : " << x << "\n";
#define _ cin.sync_with_stdio(0); cin.tie(0);


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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int N = 100123;
int cost[N][2];

vector<pair<int, pii> > G[N];

void dfs(int u, int p){
    trav(x, G[u]){
        int v = x.F;
        if(v != p){
            cost[v][0] = cost[u][0] + x.S.F;
            cost[v][1] = cost[u][1] + x.S.S;
            dfs(v, u);
        }
    }
}


typedef vector<pii> vpi;
typedef vector<vpi> graph;
const pii inf(1 << 29, -1);

template <class T>
struct RMQ {
	vector<vector<T>> jmp;

	RMQ(const vector<T>& V) {
		int N = sz(V), on = 1, depth = 1;
		while (on < sz(V)) on *= 2, depth++;
		jmp.assign(depth, V);
		rep(i,0,depth-1) rep(j,0,N)
			jmp[i+1][j] = min(jmp[i][j],
			jmp[i][min(N - 1, j + (1 << i))]);
	}

	T query(int a, int b) {
		if (b <= a) return inf;
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	vi time;
	vector<ll> dist;
	RMQ<pii> rmq;

	LCA(graph& C) : time(sz(C), -99), dist(sz(C)), rmq(dfs(C)) {}

	vpi dfs(graph& C) {
		vector<tuple<int, int, int, ll> > q(1);
		vpi ret;
		int T = 0, v, p, d; ll di;
		while (!q.empty()) {
			tie(v, p, d, di) = q.back();
			q.pop_back();
			if (d) ret.emplace_back(d, p);
			time[v] = T++;
			dist[v] = di;
			trav(e, C[v]) if (e.first != p)
				q.emplace_back(e.first, v, d+1, di + e.second);
		}
		return ret;
	}

	int query(int a, int b) {
		if (a == b) return a;
		a = time[a], b = time[b];
		return rmq.query(min(a, b), max(a, b)).second;
	}
	ll distance(int a, int b) {
		int lca = query(a, b);
		return dist[a] + dist[b] - 2 * dist[lca];
	}
};


int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int t = nxt();
    while(t--){
        int n = nxt();
        rep(i,0,n) G[i].clear();
        graph g_lca(n);
        ll ans = 0;
        rep(i,0,n - 1){
            int u = nxt() -1, v = nxt() - 1, c1 = nxt(), c2 = nxt();
            g_lca[u].push_back({v, 1});
            g_lca[v].push_back({u, 1});
            G[u].push_back({v, {c1, c2}});
            G[v].push_back({u, {c2, c1}});
            ans += c1 + c2;
        }
        memset(cost, 0, sizeof cost);
        LCA lca(g_lca);
        dfs(0, -1);
        int q = nxt();
        while(q--){
            int x = nxt() - 1, y = nxt() - 1, v = lca.query(x, y);
            ll dist = cost[y][1] + cost[x][0] - cost[v][0] - cost[v][1];
            cout << ans - dist << '\n';
        }

    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}