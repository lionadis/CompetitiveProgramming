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

const int N = 1234;
int a[N][N], mst[N][N], d[N][N];
bool vis[N];
pii edges[N * N];

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
	}
};

const int INF = (int)1e9 + 7;

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int t = nxt();
    while(t--){
        int n = nxt();
        UF uf(n);
        rep(i,0,n) rep(j,0,n) a[i][j] = nxt();
        ll ans = 0;
        int e = 0;
        rep(i,0,n){
            rep(j,i+1,n){
                ans += abs(a[i][j] - a[j][i]);
                a[i][j] = max(a[i][j], a[j][i]);
                a[j][i] = max(a[i][j], a[j][i]);
                edges[e++] = {i, j};
            }
        }
        sort(edges, edges + e, [&](pii &x, pii &y){
            return a[x.F][x.S] > a[y.F][y.S];
        });
        int mst_e = n - 1, idx = 0;
        rep(i,0,n) rep(j,0,n) mst[i][j] = 0;
        while(mst_e){
            int u = edges[idx].F, v = edges[idx].S;
            idx++;
            if(uf.same_set(u, v)) continue;
            mst[u][v] = mst[v][u] = a[u][v];
            uf.join(u, v);
            mst_e--;
        }
        rep(i,0,n) rep(j,0,n) d[i][j] = d[j][i] = INF;
        rep(i,0,n) d[i][i] = 0;
        rep(i,0,n){
            memset(vis, 0, sizeof vis);
            queue<pair<int, int> > Q;
            Q.push({i, INF});
            while(!Q.empty()){
                int u = Q.front().F, w = Q.front().S;
                Q.pop();
                if(vis[u]) continue;
                vis[u] = true;
                rep(v,0,n){
                    if(mst[u][v] != 0){
                        int w1 = min(w, mst[u][v]);
                        if(d[i][v] != INF) continue;
                        d[i][v]  = min(w1, d[i][v]);
                        Q.push({v, w1});
                    }
                }
            }
        }
        rep(i,0,n){
            rep(j,0,n){
                if(d[i][j] != INF) ans += d[i][j] - a[i][j];
            }
        }
        cout << ans << '\n';
        
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}