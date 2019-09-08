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



int root(ll x){
    int l = 0, r = 1e6;
    while(l < r){
        ll mid = (l + r + 1) / 2;
        if(mid * mid <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

ll sum(ll x, ll y){
    return 1LL * (x + y +  1) * (y - x) / 2;
}

long double count(ll x){
    int y = root(x);
    long double ans = 0;
    rep(i, 1, y) ans += x / i * i;
    rep(i, 1, y + 1) ans += sum(x / (i + 1), x / i) * i;
    return ans;
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    cout << fixed;
    ll a = nxt<ll>(), b = nxt<ll>();
    long double ans = count(b) - count(a - 1);
    cout << setprecision(0) << floor(ans) << '\n';
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}