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

const ll INF = (ll)1e16 + 123;
const int N = 5123;
int cnt[N];
pii a[N], b[N];

ll dist(int j, int i){
    return 1ll * (a[i].F - b[j].F) * (a[i].F - b[j].F) + 1ll * (a[i].S - b[j].S) * (a[i].S - b[j].S);
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n = nxt(), m = nxt();
    rep(i,0,n) a[i] = {nxt(), nxt()};
    rep(i,0,m) b[i] = {nxt(), nxt()};
    int ans = 0;
    rep(i,0,m){
        ll curr_dist = INF;
        int curr_cat = -1;
        rep(j,0,n){
            if(curr_dist > dist(i, j)) curr_cat = j, curr_dist = dist(i, j);
        }
        cnt[curr_cat] ++;
    }
    rep(i,0,n) if(cnt[i] == 1) ans++;
    cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}