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

const int MAX_PR = 1000123;
bitset<MAX_PR> isprime;
vi sieve(int lim=MAX_PR){
    isprime.set(), isprime[0] = isprime[1] = 0;
    for(int i=4; i < lim; i += 2) isprime[i] = 0;
    for(int i=3; i*i < lim; i += 2) if(isprime[i])
    for(int j=i* i; j < lim; j += 2 * i) isprime[j] = 0;
        
    vi pr;
    rep(i,2,lim) if(isprime[i]) pr.push_back(i);
    return pr;
}
const int maxn = 100123;
int cnt[maxn];
vi primes;

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    primes = sieve();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(cnt, 0, sizeof cnt);
        rep(i,0,n){
            int x;
            cin >> x;
            rep(i,0,sz(primes)){
                if(primes[i] * primes[i] > x) break;
                if(x % primes[i] == 0){
                    cnt[i] ++;
                    while(x % primes[i] == 0) x /= primes[i];
                }
            }
            if(x != 1){
                int idx = lower_bound(all(primes), x) - primes.begin();
                cnt[idx] ++;
            }
        }
        int ans = 0;
        rep(i,0,sz(primes)) ans += (cnt[i] + 2) / 3;
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}