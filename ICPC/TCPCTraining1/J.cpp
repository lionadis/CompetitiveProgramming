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

const int inf = (int) 2e9;
int dist[123][123][212];


struct edge{
    int x, y, t, c;
    bool operator<(const edge& e) const{
        return c > e.c;
    }
};

vector<edge> E[123][123];
bool vis[123][123][212];


int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t = nxt();
    rep(T, 1, t + 1){
        int n = nxt(), m = nxt(), x = nxt() - 1, y = nxt() - 1;
        int p = nxt();
        rep(i,0,n){
            rep(j,0,m) E[i][j].clear();
        }
        rep(i,0,p){
            int x1 = nxt() - 1, y1 = nxt() - 1, x2 = nxt() - 1, y2 = nxt() - 1, c = nxt(), t = nxt();
            E[x1][y1].push_back({x2, y2, t, c});
        }
        rep(i,0,n){
            rep(j,0,m){
                rep(k,0,212){
                    dist[i][j][k] = inf;
                    vis[i][j][k] = false;
                }
            }
        }

        priority_queue<edge> PQ;
        PQ.push({x, y, 100, 0});
        dist[x][y][100] = 0;
        while(!PQ.empty()){
            edge e = PQ.top();
            PQ.pop();
            if(vis[e.x][e.y][e.t]) continue;    
            //cout << e.x << " " << e.y << " " << e.t << " " << e.c << '\n';
            vis[e.x][e.y][e.t] = true;
            trav(v, E[e.x][e.y]){
                if(v.t + e.t > 200 || v.t + e.t < 0) continue;
                //cout << v.x << " " << v.y << " " << v.t << " " << v.c << '\n';
                if(dist[v.x][v.y][v.t + e.t] > e.c + v.c) dist[v.x][v.y][v.t + e.t] = e.c + v.c, PQ.push({v.x, v.y, v.t + e.t, e.c + v.c});
            }
        }
        int q = nxt();
        cout << "Case " << T << ":\n";
        while(q--){
            int a = nxt() - 1, b = nxt() - 1, w = nxt() + 100;
            if(dist[a][b][w] >= inf) cout << "No\n";
            else cout << dist[a][b][w] << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}