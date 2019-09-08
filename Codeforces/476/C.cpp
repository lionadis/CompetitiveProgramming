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

ll n, k, m, d;

ll check(ll x) { 
    if (x==0) return (ll)-1e18;
    ll ans = 
	return (n + k * x - x) / (k * x);
}

ll solve(ll x)
{
	ll l = 0, r = m + 1;
	while (l + 1 < r)
	{
		ll mid1 = (r + l) >> 1;
		if (check(mid1) < x) r = mid1;
		else l = mid1;
	}
	return l;
}


int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    n = nxt<ll>(), k = nxt<ll>(), m = nxt<ll>(), d = nxt<ll>();
    ll ans = 0;
    rep(i,1,d+1) ans = max(ans, solve(i) * i);
    cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}