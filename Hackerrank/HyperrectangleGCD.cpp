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
const int MOD = (int) 1e9 + 7;
int phi[MAXN];

ll mul(ll a, ll b){
    return ((a % MOD * b % MOD) % MOD + MOD) % MOD;
}

ll sum(ll a, ll b){
    return ((a % MOD + b % MOD) % MOD + MOD) % MOD;
}

ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	ll x = modpow(a * a % MOD, e >> 1);
	return e & 1 ? x * a % MOD : x;
}
int cnt = 0;
void sieve(){ // nloglogn
    rep(i,1,MAXN) phi[i] = i;
    rep(i,2,MAXN){
        if(phi[i] == i)
            for(int j=i;j<MAXN;j+=i) (phi[j] /= i) *= (i - 1), cnt ++;
    }
}

void sieve2(){ //nlogn
    rep(i,1,MAXN) phi[i] = i;
    rep(i,1,MAXN){
        for(int j=i+i;j<MAXN;j+=i) phi[j] -= phi[i], cnt++;
    }
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    sieve();
    cout << cnt << '\n';
    rep(i,1,10) cout << phi[i] << " ";
    int t = nxt();
    int a[510];
    while(t--){
        int n = nxt(), max_gcd = 1e9;
        ll N = 1, ans = 0;
        rep(i,0,n) a[i] = nxt(), N = mul(N, a[i]), max_gcd = min(max_gcd, a[i]);
        rep(k,1,max_gcd + 1){
            ll tmp = 1;
            rep(i,0,n) tmp = mul(tmp, a[i] / k);
            ans = sum(ans, mul(tmp, phi[k]));
        }  
        cout << ans << '\n';
    }
    tl;
}