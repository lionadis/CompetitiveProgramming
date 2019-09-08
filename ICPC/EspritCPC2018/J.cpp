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

const int maxn = 1012;
const int inf = (int) 1e9 + 7;
int a[maxn], dist[maxn], n;
bool vis[maxn];
vector<vi> G;

int bfs(int src){
    queue<int> Q;
    Q.push(src);
    dist[src] = 0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        trav(v, G[u]){
            if(dist[v] > dist[u] + 1) dist[v] = dist[u] + 1, Q.push(v);
        }
    }
    return *max_element(dist, dist + n);
}

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t = nxt();
    while(t--){
        n = nxt();
        G.clear();
        G.resize(n);
        rep(i,0,n) a[i] = nxt();
        rep(i,0,n){
            rep(j,0,a[i]){
                int x = nxt() - 1;
                G[i].push_back(x);
            }
        }
        int ans = inf;
        rep(i,0,n){
            fill(dist, dist + n, inf);
            fill(vis, vis + n, false);
            ans = min(ans, bfs(i));
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}