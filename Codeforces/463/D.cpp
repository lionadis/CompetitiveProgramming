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

const int maxn = 400123;
const int lgn = 19;
const ll inf = 1e15 + 123;
ll f[lgn][maxn], g[lgn][maxn], w[maxn];

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int q = nxt(), cnt = 1;
    ll last = 0;
    rep(i,0,lgn){
        rep(j,0,10) g[i][j] = inf;
    }
    f[0][cnt] = 0;
    g[0][cnt] = 0;
    while(q--){
        ll type = nxt(), r = nxt<ll>() ^ last, w = nxt<ll>() ^ last;
        // cout << "Q = "<< type << " " << r << " " << w << '\n';
        if(type == 1){
            ++ cnt;
            for(int i=lgn - 1; i >= 0; --i)
                if(g[0][f[i][r]] < w) r = f[i][r];
            if(g[0][r] < w) r = f[0][r];
            f[0][cnt] = r, g[0][cnt] = w;
            // cout << "r = " << r << '\n';
            rep(i,1,lgn){
                f[i][cnt] = f[i - 1][f[i - 1][cnt]];
                g[i][cnt] = g[i - 1][cnt] + g[i - 1][f[i - 1][cnt]];
            }
        } else {
            last = 0;
            for(int i=lgn - 1;i>=0;--i){
                if(g[i][r] <= w){
                    w -= g[i][r];
                    last += 1 << i;
                    r = f[i][r];
                }
            }
            cout << last << '\n';
        }
        
        // rep(k,0,2){
        //     rep(i,1,cnt+1) cout << f[k][i] << "/" << g[k][i] << " ";
        //     cout << '\n';
        // }
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}