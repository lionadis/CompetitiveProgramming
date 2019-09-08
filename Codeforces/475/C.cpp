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

const int N = 1010;
int cnt[N];

const int MOD = (int) 1e9 + 9;

int binpow(int n,int k)
{
    int ret=1;
    while(k)
    {
        if(k&1)
            ret=1ll*ret*n%MOD;
        n=1ll*n*n%MOD;
        k/=2;
    }
    return ret;
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n,a,b,k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    ll curr=0;
    rep(i,0,k)
    {
        if(s[i] == '+')
            curr += 1ll * binpow(a,n-i) * binpow(b,i) % MOD;
        else
            curr -= 1ll * binpow(a,n-i) * binpow(b,i) % MOD;
        if(curr >= MOD)
            curr -= MOD;
        if(curr < 0)
            curr += MOD;
    }
    ll scale = 1ll * binpow(a, 1ll * k * (MOD - 2) % (MOD - 1)) * binpow(b ,k) % MOD;
    int ans = 1;
    if(scale == 1)
        ans = curr * ((n + 1) / k) % MOD;
    else
        ans = curr * (binpow(scale, (n + 1) / k) - 1) % MOD * binpow(scale - 1,MOD - 2) % MOD;
    cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}