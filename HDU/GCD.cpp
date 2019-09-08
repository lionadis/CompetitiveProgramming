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
#define debug(x) cerr << #x << " : " << x << "\n";
#define _ cin.sync_with_stdio(0); cin.tie(0);
#define tl cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n"
#define Func {ans += solve(i); ++i;}


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

const int MAXN = (int) 1e5 + 123;
int mu[MAXN];
void sieve(){
    mu[1] = 1;
    rep(i,1,MAXN){
        for(int j=2*i;j<MAXN;j+=i) mu[j] -= mu[i];
    }
}

ll solve(ll x, ll y, ll k){
    ll ans = 0;
    rep(i,1,MAXN) ans += 1LL * mu[i] * (x / (k * i)) * (y / (k * i))    ;
    return ans;
}

ll solve2(ll x, ll y, ll k){
    return solve(x, y, k) - solve(min(x, y), min(x, y), k) / 2;
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int t = nxt();
    sieve();
    while(t--){
        int a = nxt(), b = nxt(), c = nxt(), d = nxt(), k = nxt();
        ll ans = 0;
        ans += solve2(b, d, k);
        ans -= solve2(b, c - 1, k);
        ans -= solve2(d, a - 1, k);
        ans += solve2(a - 1, c - 1, k);
        cout << ans << '\n';
    }
}