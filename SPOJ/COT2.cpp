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

//LCA
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

typedef vector<pii> vpi;
typedef vector<vi> graph;

struct LCA {
	vi time;
	RMQ<pii> rmq;

	LCA(graph& C) : time(sz(C), -99), rmq(dfs(C)) {}

	vpi dfs(graph& C) {
		vector<tuple<int, int, int> > q(1);
		vpi ret;
		int T = 0, v, p, d;
		while (!q.empty()) {
			tie(v, p, d) = q.back();
			q.pop_back();
			if (d) ret.emplace_back(d, p);
			time[v] = T++;
			trav(e, C[v]) if (e != p)
				q.emplace_back(e, v, d+1);
		}
		return ret;
	}

	int query(int a, int b) {
		if (a == b) return a;
		a = time[a], b = time[b];
		return rmq.query(min(a, b), max(a, b)).second;
	}
};
//LCA

const int maxn = 40123;
const int maxq = 100123;
int a[maxn], tin[2 * maxn], tout[2 * maxn], ord[2 * maxn], timer = 0, SQRT, curr_ans, ans[maxq];
bool vis[maxn];
vector<vi> G;
unordered_map<int, int> cnt;

void dfs(int u, int p = -1){
    ord[timer] = u;
    tin[u] = timer ++;
    trav(v, G[u]){
        if(v != p) dfs(v, u);
    }
    ord[timer] = u;
    tout[u] = timer ++;
}

struct query{
    int L, R, lca, idx;
}Q[maxq];

bool cmp(query &a, query &b){
    if(a.L / SQRT != b.L / SQRT) return a.L / SQRT < b.L / SQRT;
    return a.R < b.R;
}


void add(int x){
    if(vis[x]){
        if(--cnt[a[x]] == 0) curr_ans--;
    }
    if(!vis[x]){
        if(cnt[a[x]]++ == 0) curr_ans++;
    }
    vis[x] ^= 1;
}




int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int n = nxt(), q = nxt();
    G.resize(n);
    rep(i,0,n) a[i] = nxt();
    rep(i,0,n - 1){
        int u = nxt() - 1, v = nxt() - 1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0);
    LCA lca(G);
    rep(i,0,q){
        int u = nxt() - 1, v = nxt() - 1;
        int w = lca.query(u, v);
        if(w == u) Q[i] = {tin[u], tin[v], -1, i};
        else if(w == v) Q[i] = {tin[v], tin[u], -1, i};
        else {
            Q[i] = {min(tout[u], tout[v]), max(tin[u], tin[v]), w, i};
        }
    }
    SQRT = sqrt(timer + .0) + 1;
    sort(Q, Q + q, cmp);
    int currL = 0, currR = -1;
    rep(i,0,q){
        while(currL > Q[i].L) add(ord[--currL]);
        while(currL < Q[i].L) add(ord[currL++]);
        while(currR < Q[i].R) add(ord[++currR]);
        while(currR > Q[i].R) add(ord[currR--]);
        if(Q[i].lca != -1) add(Q[i].lca);
        ans[Q[i].idx] = curr_ans;
        if(Q[i].lca != -1) add(Q[i].lca);
    }
    rep(i,0,q) cout << ans[i] << '\n';
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}