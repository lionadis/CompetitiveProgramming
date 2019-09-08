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
typedef vector<double> vd;

const int maxn = 50123;
vi primes;
ll ans, n;

typedef vector<pii> vpi;
typedef vector<vpi> graph;
const pii inf(1 << 29, -1);

graph G;

bitset<maxn> is_prime;
void sieve(){
    is_prime.set(), is_prime[0] = is_prime[1] = 0;
    for(int i = 4; i < maxn; i += 2) is_prime[i] = 0;
    for(int i = 3; i * i <= maxn; i += 2){
        if(is_prime[i]){
            for(int j = i*i; j < maxn; j += 2 * i) is_prime[j] = 0;
        }
    }
}

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



int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    cin >> n;
    sieve();
    G.resize(n);
    rep(i,0,n - 1){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back({v, 1});
        G[v].push_back({u, 1});
    }
    LCA lca(G);
    rep(i,0,n){
        rep(j,i + 1,n) if(is_prime[lca.distance(i, j)]) ans++;
    }
    cout << fixed << setprecision(10) << 1.0 * ans / (n * (n - 1) / 2) << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}