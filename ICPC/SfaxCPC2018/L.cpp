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

const int maxn = 100123;
bool vis[maxn];
double dist[maxn];

struct cmp{
    bool operator ()(const pair<int, double> &p1, const pair<int, double> &p2){
    return p1.S < p2.S;
    }
};

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    freopen("path.in", "r", stdin);
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        unordered_map<ll, double> mp;
        vector<vector<pair<int, double> > > G(n);
        rep(i,0,m){
            ll u, v;
            double w;
            cin >> u >> v >> w;
            u--, v--;
            if(u == v) continue;
            if(u > v) swap(u, v);
            mp[(u << 20) + v] = max(mp[(u << 20) + v], w);
        }
        trav(p, mp){
            int u = (((1LL << 40) - 1) & p.F) >> 20;
            int v = (((1LL << 20) - 1) & p.F);
            G[u].push_back({v, p.S});
            G[v].push_back({u, p.S});
        }
        fill(dist, dist + n, 0);
        fill(vis, vis + n, 0);
        dist[0] = 1;
        priority_queue<pair<int, double> , vector<pair<int, double>> , cmp> PQ;
        PQ.push({0, 1});
        while(!PQ.empty()){
            pair<int, double> curr = PQ.top();
            int u = curr.F;
            double curr_w = curr.S;
            PQ.pop();
            if(vis[u]) continue;
            vis[u] = true;
            trav(p, G[u]){
                int v = p.F;
                double w = p.S;
                if(dist[v] < w * curr_w) dist[v] = w * curr_w, PQ.push({v, w * curr_w});
            }
        }
        cout << fixed << setprecision(2) << dist[n - 1] << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}