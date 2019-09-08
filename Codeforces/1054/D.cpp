#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

const int maxn = 200123;

ll a[maxn];
unordered_map<ll, ll> cnt;

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    ll n = nxt(), k = nxt();
    ll m = 1 << k; m--; a[0] = 0, cnt[0] = 1;
    rep(i,1,n + 1){
        ll x = nxt();
        a[i] = a[i - 1] ^ x;
    }
    rep(i,1,n + 1){
        ll v = min(a[i], a[i] ^ m);
        cnt[v]++;
    }
    ll ans = n * 1ll * (n - 1) / 2; ans += n;
    trav(q, cnt) {
        ll w = q.S;
        ll v = w/2; w -= v;
        ans -= v * (v - 1) / 2; ans -= w * (w - 1) / 2;
    }
    cout << ans << endl;
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}