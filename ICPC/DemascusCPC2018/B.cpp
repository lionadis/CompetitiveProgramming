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

const int N = 4012;
const int base1 = 970592641, base2 = 987654323;
const int mod1 = (int) 1e9 + 7, mod2 = (int) 1e9 + 9;
int a[N];

struct arrayhash{
    vector<ll> P, H;
    ll base, mod;
    arrayhash(){}
    arrayhash(const int *a, int n, ll b, ll m){
        P.resize(n + 3, 1), H.resize(n + 3, 0);
        base = b, mod = m;
        rep(i,1,n + 1) P[i] = (P[i - 1] * base) % mod;
        rep(i,1,n + 1) H[i] = (H[i - 1] + P[a[i - 1]]) % mod;
    }

    ll range_hash(int a, int b){
        return ((H[b] - H[a - 1]) + mod) % mod;
    }
};

struct doublehash{
    arrayhash h1, h2;
    doublehash(const int* a, int n){
        h1 = arrayhash(a, n, base1, mod1);
        h2 = arrayhash(a, n, base2, mod2);
    }

    ll range_hash(int a, int b){
        return (h1.range_hash(a, b) << 32) ^ h2.range_hash(a, b);
    }
};

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t = nxt();
    while(t--){
        int n = nxt();
        unordered_map<ll, int> f, f2;
        rep(i,0,n){
            int u = nxt(), v = nxt();
            if(u < v) swap(u, v);
            int x = u * N + v;
            if(!f.count(x)) f[x] = f.size() + 1;
            a[i] = f[x];
        }
        doublehash h = doublehash(a, n);
        ll ans = 0;
        rep(i,1,n + 1){
            rep(j,i,n + 1){
                ll x = h.range_hash(i, j);
                ans += f2[x]++;
            }
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}