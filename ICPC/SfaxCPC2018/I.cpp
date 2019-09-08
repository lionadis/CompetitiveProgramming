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
int color[maxn];
bool vis[maxn];

vector<vi> G;

bool bfs(int src){
    queue<int> Q;
    Q.push(src);
    color[src] = 0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        trav(v, G[u]){
            if(color[v] == color[u]){
                return false;
            }
            Q.push(v);
            color[v] = 1 - color[u];
        }
    }
    return true;
}


int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    freopen("team.in", "r", stdin);
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t = nxt();
    while(t--){
        int n = nxt(), m = nxt();
        G.clear();
        G.resize(n);
        if(n <= 1){
            cout << "NO\n";
            continue;
        }
        rep(i,0,m){
            int u = nxt() - 1, v = nxt() - 1;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        fill(color, color + n, -1);
        fill(vis, vis + n, 0);
        bool ans = true;
        rep(i,0,n){
            if(!vis[i]) ans = ans && bfs(i);
        }
        cout << (ans ? "YES\n" : "NO\n");
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}