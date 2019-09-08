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

inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}

template<typename T = int>
inline T nxt()
{
    char c=nc();
    T x=0;
    int f=1;
    for(; c>'9'||c<'0'; c=nc())if(c=='-')f=-1;
    for(; c>='0'&&c<='9'; x=x*10+c-'0',c=nc());
    x*=f;
    return x;
}

const ll MOD = 1000000007; // faster if const
ll modpow(ll a, ll e)
{
    if (e == 0) return 1;
    ll x = modpow(a * a % MOD, e >> 1);
    return e & 1 ? x * a % MOD : x;
}

ll mul(ll a, ll b){
    return ((a%MOD) * (b%MOD))%MOD;
}

ll sum(ll a, ll b){
    return ((a%MOD + b%MOD)%MOD+MOD)%MOD;
}

const int N = 123456;
int n, m, s1[N], s2[N];
ll dp[N];

ll solve(int idx)
{
    if(idx == n) return 0;
    ll& ans = dp[idx];
    if(~ans) return ans;
    if(s1[idx] == 0 && s2[idx] != 0){
        return ans = sum(mul((m-s2[idx]), modpow(m, MOD-2)), mul(solve(idx+1), modpow(m, MOD-2)));
    }
    if(s2[idx] == 0 && s1[idx] != 0){
        return ans = sum(mul(s1[idx]-1, modpow(m, MOD-2)), mul(solve(idx+1), modpow(m, MOD-2)));
    }
    if(s1[idx] == 0 && s2[idx] == 0){
        return ans = sum(mul(m-1, modpow(mul(m,2), MOD-2)), mul(solve(idx+1), modpow(m, MOD-2)));
    }
    if(s1[idx] < s2[idx]) return ans = 0;
    if(s1[idx] > s2[idx]) return ans = 1;
    return ans = solve(idx+1);
}

int main()
{
#ifndef ONLINE_JUDGE
    f_in
#else
    _
#endif
    n = nxt(), m = nxt();
    rep(i,0,n) s1[i] = nxt();
    rep(i,0,n) s2[i] = nxt();
    memset(dp, -1, sizeof dp);
    cout << solve(0) << '\n';
}
