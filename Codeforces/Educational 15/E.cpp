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
const int lgn = 50;
int n, f[lgn][maxn], h[lgn][maxn];
ll g[lgn][maxn], k;

void solve(int u){
    ll s = 0;
    int m = 1e8 + 123;
    ll kk = k;
    for(int i = lgn - 1; i >= 0; --i){
        if(kk & (1LL << i)){
            s += g[i][u];
            m = min(m, h[i][u]);
            u = f[i][u];
        }
    }
    cout << s << " " << m << '\n';
}

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    n = nxt(), k = nxt<ll>();
    rep(i,0,n) f[0][i] = nxt();
    rep(i,0,n) g[0][i] = h[0][i] = nxt();
    rep(i,1,lgn){
        rep(u,0,n){
            f[i][u] = f[i - 1][f[i - 1][u]];
            g[i][u] = g[i - 1][u] + g[i - 1][f[i - 1][u]];
            h[i][u] = min(h[i - 1][u], h[i - 1][f[i - 1][u]]);
        }
    }
    rep(i,0,n) solve(i);


#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}