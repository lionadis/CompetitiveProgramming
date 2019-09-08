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

const int maxn = 10000123;
ll f1[maxn], f2[maxn];

ll solve1(ll n){
    if(n < maxn) return f1[n];
    return n - 1 + solve1(n / 2) + solve1((n + 1) / 2);
}

ll solve2(ll n){
    if(n < maxn) return f2[n];
    return n / 2 + solve2(n / 2) + solve2((n + 1) / 2);
}

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    f1[0] = f1[1] = f2[0] = f2[1] = 0;
    rep(i,2,maxn) f1[i] = i - 1 + f1[i / 2] + f1[(i + 1) / 2];
    rep(i,2,maxn) f2[i] = i / 2 + f2[i / 2] + f2[(i + 1) / 2];
    int t;
    cin >> t;
    rep(i,1,t + 1){
        ll n;
        cin >> n;
        cout << i << ". " << solve2(n) << "/" << solve1(n) << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}