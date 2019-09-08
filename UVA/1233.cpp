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

const int maxn = 512;
int a[maxn], dist[maxn][maxn];
bool vis[maxn][maxn];
vector<vector<pii> > G;

void solve(int *d,int src){
    d[src] = 0;
    priority_queue<pii> PQ;
    PQ.push({0, src});
    while(!PQ.empty()){
        int u = PQ.top().S;
        PQ.pop();
        if(vis[src][u]) continue;
        vis[src][u] = true;
        trav(p, G[u]){
            int v = p.F, dst = p.S;
            if(d[v] > d[u] + dst){
                d[v] = d[u] + dst;
                PQ.push({-d[v], v});
            }
        }
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else 
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int tc;
    cin >> tc;
    while(tc--){
        memset(dist, 0x3f, sizeof dist);
        memset(vis, 0, sizeof vis);
        int b, p, q;
        cin >> b >> p >> q;
        G.clear();
        G.resize(p + 1);
        rep(i,0,q) cin >> a[i];
        rep(i,0,p){
            int r;
            cin >> r;
            rep(j,0,r){
                int c, v;
                cin >> c >> v;
                G[i+1].push_back({v, c});
            }
        }
        rep(i,0,q) {
            solve(dist[a[i]], a[i]);
        }
        int cycle = 1e9;
        rep(i,0,q) cycle = min(cycle, dist[a[i]][0]);
        int step = cycle, ans = 0;
        while(step < b) step += cycle - 1, ans++;
        cout << ans << '\n';
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}