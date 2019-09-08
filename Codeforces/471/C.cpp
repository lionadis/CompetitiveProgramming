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
#define tl cerr <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n"
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

const int MAX_PR = 65;
bitset<MAX_PR> isprime;
vi eratosthenes_sieve(int lim = MAX_PR) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}

vi primes;
vector<pair<int, int> > powers;

void solve(int idx, int curr_pow, int signe){
    if(curr_pow > 70) return;
    if(idx >= sz(primes)) {
        if(curr_pow != 1) powers.push_back({curr_pow, signe});
        return;
    }
    solve(idx + 1, curr_pow, signe);
    solve(idx + 1, curr_pow * primes[idx], (-1) * signe);
}

int nth_sqrt(ll x, int n){
    int l = 0, r = (int)pow(2e18, 1.0 / n);
    while(l < r){
        int mid = (l + r + 1) / 2;
        ll tmp = 1;
        rep(i,0,n) tmp *= mid;
        if(tmp <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}
int count(ll n){
    if(n == 0) return 0;
    int idx = 0;
    int res = 1;
    int x = nth_sqrt(n, powers[idx].F);
    while(idx < sz(powers)&&  x != 1) res += (x - 1) * powers[idx].S, idx++, x = nth_sqrt(n, powers[idx].F);
    return res;
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    primes = eratosthenes_sieve();
    solve(0, 1, -1);
    sort(all(powers));
    int q = nxt();
    while(q--){
        ll l = nxt<ll>(), r = nxt<ll>();
        int ans = count(r) - count(l - 1);
        cout << ans << '\n';
    }
}