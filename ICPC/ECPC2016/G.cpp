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

const int mod = (int)1e9 + 7;
const int maxn = 1012;
ll s[maxn][maxn], fact[maxn];


int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    freopen("galactic.in", "r", stdin);
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t = nxt();
    fact[0] = 1;
    rep(i,1,maxn) fact[i] = (fact[i - 1] * i) % mod;
    rep(i,1,maxn) s[i][1] = 1, s[i][i] = 1;
    rep(i,2,maxn){
        rep(j,2,i){
            s[i][j] = (s[i - 1][j - 1] + j * s[i - 1][j]) % mod;
        }
    }
    while(t--){
        int n = nxt(), k = nxt();
        if(k > n) cout << "0\n";
        else cout << (s[n][k] * fact[k]) % mod << '\n'; 
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}