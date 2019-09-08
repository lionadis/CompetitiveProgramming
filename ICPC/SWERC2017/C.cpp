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

const int N = 8;
const int MOD = (int) 1e9;
int n;
ll m;

ll mul(ll a, ll b){
    return (a * b) % MOD;
}

ll sum(ll a, ll b){
    return (a + b) % MOD;
}

ll cnt = 0;

struct M{
    ll val[260][260];
    M (){
        rep(i,0,1 << n){
            rep(j,0,1 << n) val[i][j] = 0;
        }
    };
    M operator*(const M &b){
        M ans;
        rep(i,0,1 << n) rep(j,0,1 << n)
        rep(k,0,1 << n) ans.val[i][j] = sum(ans.val[i][j], mul(val[i][k], b.val[k][j]));
        return ans;
    }
};

M a;

void solve(int idx, int curr, int mask){
    if(idx >= n){
        a.val[mask][curr] ++;
        return;
    }
    int k = (mask & 1 << idx) >> idx, k2 = (mask & 1 << (idx + 1)) >> (idx + 1);
    solve(idx + 1, curr | ((k ^ 1) << idx), mask);
    if(!k) solve(idx + 1, curr, mask);
    if(idx + 1 < n && !k && !k2) solve(idx + 2, curr, mask);
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    n = nxt(), m = nxt<ll>();
    rep(mask, 0, 1 << n) solve(0, 0, mask);
    M ans;
    rep(i,0,1 << n) ans.val[i][i] = 1;
    cnt = 0;
    ans = ans * ans;
    while(m){
        if(m & 1) ans = ans * a;
        a = a * a;
        m /= 2;
    }
    cout << ans.val[0][0] << '\n';
}