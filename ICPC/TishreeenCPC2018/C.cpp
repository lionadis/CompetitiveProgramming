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

const int maxn = 123;
int a[maxn][maxn], s[maxn][maxn];

int sum(int u, int l, int d, int r){
    return s[d][r] - s[d][l] - s[u][r] + s[u][l];
}

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        rep(i,0,n)
            rep(j,0,m) cin >> a[i][j];
        rep(i,0,n)
            rep(j,0,m) s[i+1][j+1] = a[i][j] + s[i+1][j] + s[i][j+1] - s[i][j];

        int ans = 0;
        rep(x1,0,n)
            rep(y1,0,m)
                rep(x2,x1+1,n+1)
                    rep(y2,y1+1,m+1) if(sum(x1,y1,x2,y2) <= k) ans = max(ans, (x2 - x1) * (y2 - y1));
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}