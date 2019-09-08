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

const int N = 100123;
const int inf = (int)1e9 + 7;
int a[N], dist[N], n;
bool vis[N];
vector<vi> G;

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    freopen("jumping.in", "r", stdin);
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t = nxt();
    while(t--){
        memset(vis, -1, sizeof vis);
        n = nxt();
        G.clear();
        G.resize(n);
        rep(i,0,n){
            a[i] = nxt();
            if(i - a[i] >= 0) G[i - a[i]].push_back(i);
            if(i + a[i] < n) G[i + a[i]].push_back(i);
        }
        fill(dist, dist + n, inf);
        memset(vis, 0, sizeof vis);
        dist[n - 1] = 0;
        queue<int> q;
        q.push(n - 1);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(vis[u]) continue;
            vis[u] = true;
            trav(v, G[u]){
                if(dist[v] > dist[u] + 1) dist[v] = dist[u] + 1, q.push(v);
            }
        }
        rep(i,0,n) cout << (dist[i] >= inf ? -1 : dist[i]) << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}