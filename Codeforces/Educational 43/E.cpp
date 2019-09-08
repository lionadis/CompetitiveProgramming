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

const int N = 200123;
pii p[N];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n = nxt(), a = nxt(), b = nxt();
    ll sum = 0;
    rep(i,0,n) p[i] = {nxt(), nxt()}, sum += p[i].S;
    sort(p, p + n, [&](pii &x, pii &y){
        return x.F - x.S > y.F - y.S;
    });
    rep(i,0,b){
        if(p[i].F > p[i].S) sum += p[i].F, sum -= p[i].S;
    }
    ll ans = sum;
    rep(i,0,b){
        ans = max(ans, ((ll) p[i].F << a) - max(p[i].F, p[i].S) + sum);
    }
    if(p[b - 1].F > p[b - 1].S){
        sum -= p[b - 1].F;
        sum += p[b - 1].S;
    }
    rep(i,b,n){
        ans = max(ans, ((ll) p[i].F << a) - max(p[i].F, p[i].S) + sum);
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}