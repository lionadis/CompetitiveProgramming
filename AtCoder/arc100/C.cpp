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

const int maxn = 200123;
int n;
ll a[maxn];

ll f(ll b){
    ll res = 0;
    rep(i,0,n) res += abs(a[i] - (b + i + 1));
    return res;
}

ll solve(int a, int b){
    while(b - a >= 5){
        int mid = (a + b) / 2;
        if(f(mid) >= f(mid + 1)) a = mid;
        else b = mid + 1;
    }
    rep(i,a+1,b+1) if(f(a) >= f(i)) a = i;
    return a;
}

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    n = nxt();
    rep(i,0,n) a[i] = nxt();
    int b = solve(-1e9, 1e9);
    cout << f(b) << '\n';



#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}