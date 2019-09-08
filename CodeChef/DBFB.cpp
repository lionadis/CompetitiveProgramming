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
#define dbg(x) cerr << #x << " : " << x << "\n";
#define _ cin.sync_with_stdio(0); cin.tie(0);


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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int MOD = (int) 1e9 + 7;
const int N = 100123;
int f[N];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    f[0] = 0, f[1] = 1;
    rep(i,2,N) f[i] = (f[i - 1] + f[i - 2]) % MOD;
    int t = nxt();
    while(t--){
        int m = nxt(), n = nxt();
        ll sa = 0, sb = 0;
        rep(i,0,m) sa += nxt();
        rep(i,0,m) sb += nxt();
        sa %= MOD, sb %= MOD;
        sa *= m, sa %= MOD;
        sb *= m, sb %= MOD;
        if(n == 1) cout << sa << '\n';
        else if(n == 2) cout << sb << '\n';
        else{
            sa *= f[n - 2], sa %= MOD;
            sb *= f[n - 1], sb %= MOD;
            cout << (sa + sb) % MOD << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}