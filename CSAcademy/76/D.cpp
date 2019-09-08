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

const int N = 100123;
pii a[N];
bool exact = true;

ll f1(int n){
    return 1LL * (n + 1) * (n + 1);
}

ll f2(int n){
    return 1LL * n * (n + 1);
}

ll intersect(int x1, int y1, int x2, int y2){
    
}

pair<ll, ll> solve(int y1, int x1, int y2, int x2){
    ll y0 = x2 - x1 + y2 + y1;
    if(y0 % 2 != 0) exact = false;
    y0 /= 2;
    ll x0 = y0 - y1 + x1;
    return {y0, x0};
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n = nxt();
    rep(i,0,n) a[i] = {nxt() - 1, nxt()};
    sort(a, a + n);
    ll ans = f1(a[0].F);
    rep(i,1,n){
        ans += f1(a[i].F);
        pii p = solve(a[i].F, a[i].S, a[i - 1].F, a[i - 1].S);
        cout << p.F + 1 << ' ' << p.S << '\n';
        if(exact) ans -= f1(p.F);
        else ans -= f2(p.F + 1);
        exact = true;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}