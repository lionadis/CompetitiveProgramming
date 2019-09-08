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
#define debug(x) cerr << #x << " : " << x << "\n";
#define _ cin.sync_with_stdio(0); cin.tie(0);
#define tl cerr <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n"
#define Func {ans += solve(i); ++i;}


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
const int N = (int) 2e6 + 123;
unordered_map<string, int> a;
int node_order[N], sorted_node[N], b, n, tot = 0;
pii node[N];
bool vis[N];
vector<vector<pair<int, pii> > > G;
vector<vi> dp;

template <class E, class I>
bool topo_sort(const E &edges, I &idx, int n) {
	vi indeg(n);
	rep(i,0,n)
		trav(e, edges[i])
			indeg[e.F]++;
	queue<int> q; // use priority queue for lexic. smallest ans.
	rep(i,0,n) if (indeg[i] == 0) q.push(-i);
	int nr = 0;
	while (q.size() > 0) {
		int i = -q.front(); // top() for priority queue
		idx[i] = nr++;
		q.pop();
		trav(e, edges[i])
			if (--indeg[e.F] == 0) q.push(-e.F);
	}
	return nr == n;
}

pii operator+(const pii &a, const pii &b){
    return {a.F + b.F, a.S + b.S};
}

void dfs(int u){
    if(vis[u]) return;
    vis[u] = true;
    if(sz(G[u]) == 0){
        node[u] = {0, 0};
        return;
    } 
    pii ans = {1e9, -1e9};
    trav(p, G[u]){
        int v = p.F;
        if(!vis[v]) dfs(v);
        pii cost_prestige = p.S + node[v];
        ans = min(ans, {cost_prestige.F, -cost_prestige.S});
    }
    node[u] = {ans.F, -ans.S};
}

int solve(int idx, int budget){
    if(budget > b) return -1e9;
    if (idx >= tot) return 0;
    int &ans = dp[idx][budget];
    if(~ans) return ans;
    return ans = max(solve(idx + 1, budget), node[idx].S + solve(idx + 1, budget + node[idx].F));
}

int trace(int idx, int budget){
    if(idx >= tot) return 0;
    if(solve(idx + 1, budget) > node[idx].S + solve(idx + 1, budget + node[idx].F)) return trace(idx + 1, budget);
    else return node[idx].F + trace(idx + 1, budget + node[idx].F);
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    cin >> b >> n;    
    G.resize(2 * n);
    rep(i,0,n){
        string s1, s2, _s;
        int cost, prestige;
        cin >> s1 >> s2 >> _s >> cost >> prestige;
        if(a.find(s1) == a.end()) a[s1] = tot++;
        if(a.find(s2) == a.end()) a[s2] = tot++;
        int u = a[s1], v = a[s2];
        G[u].push_back({v, {cost, prestige}});
    }
    topo_sort(G, node_order, tot);
    rep(i,0,tot){
        sorted_node[node_order[i]] = i;
    }
    memset(node, 0x3f3f3f3, sizeof node);
    rep(i,0,tot) if(!vis[i]) dfs(i);
    dp.resize(tot);
    rep(i,0,tot) dp[i].resize(b + 1, -1);
    cout << solve(0,0) << "\n" << trace(0,0) << '\n';
}