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

const int mod = (int) 1e9 + 7;
const int maxn = 2012;
const int maxp = maxn * maxn;
const int base = 3;
int hp, wp, hm, wm;
ll p[maxp];
ll s[maxn][maxn];

int f(int i, int j){
    return p[i * wp + j];
}

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    p[0] = 1;
    rep(i,1,maxp) p[i] = (p[i - 1] * base) % mod;
    cin >> hp >> wp >> hm >> wm;
    ll h = 0;
    rep(i,0,hp){
        string ss;
        cin >> ss;
        rep(j,0,wp){
            h += f(i, j) * (ss[j] == 'x');
            h %= mod;
        }
    }
    rep(i,0,hm){
        string ss;
        cin >> ss;
        rep(j,0,wm){
            s[i + 1][j + 1] = (s[i][j + 1] + s[i + 1][j] + f(i,j) * (ss[j] == 'x') - s[i][j] + mod) % mod;
        }
    }
    int ans = 0;
    rep(i,0,hm - hp + 1){
        rep(j,0,wm - wp + 1){
            ll val = (s[i + hp][j + wp] - s[i + hp][j] - s[i][j + wp] + s[i][j] + mod + mod) % mod;
            ans += (h * f(i,j)) % mod == val;
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}