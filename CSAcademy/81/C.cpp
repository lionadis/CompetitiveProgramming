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

int cnt[15];
const int mod = (int) 1e9 + 7;
ll fact[70];


ll mul(ll a, ll b){
    return (((a * b) % mod) + mod) % mod;
}

ll sum(ll a, ll b){
    return (((a + b) % mod) + mod) % mod;
}

ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	ll x = modpow(a * a % mod, e >> 1);
	return e & 1 ? x * a % mod : x;
}

ll modinv(ll a){
    return modpow(a, mod - 2);
}

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int n = nxt();
    fact[0] = 1;
    rep(i,1,60) fact[i] = mul(fact[i - 1], i);
    rep(i,0,n) cnt[nxt()] ++;
    ll ans = 0;
    rep(k,0,n){
        rep(i,0,10){
            if(!cnt[i]) continue;
            cnt[i]--;
            ll x = fact[n - 1];
            rep(j,0,10){
                x = mul(x, modinv(fact[cnt[j]]));
            }
            ans = sum(ans, mul(i, mul(x, modpow(10, k))));
            cnt[i] ++;
        }
    }
    ll ans1 = 0;
    if(cnt[0]){
        rep(k,0,n-1){
            rep(i,1,10){
                if(!cnt[i]) continue;
                cnt[i]--;
                ll x = fact[n - 2];
                rep(j,1,10){
                    x = mul(x, modinv(fact[cnt[j]]));
                }
                ans1 = sum(ans1, mul(i, mul(x, modpow(10, k))));
                cnt[i] ++;
            }
        }
        ans1 = mul(ans1, modinv(fact[cnt[0] - 1]));
    }
    cout << sum(ans, mul(ans1, -1)) << '\n';


#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}