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

const int N = 100123;
int n;
pii a[N];
bool vis[N];

pii operator-(const pii &a, const pii &b){
    return {a.F - b.F, a.S - b.S};
}

ll cross(pii a, pii b){
    return 1LL * a.F * b.S - 1LL * a.S * b.F;
}

bool check(){
    int x = -1, y = -1;
    rep(i,0,n){
        if(vis[i]) continue;
        if(x == -1) x = i;
        else if(y == -1) y = i;
    }
    if(y == -1) return true;
    rep(i,0,n){
        if(!vis[i] && cross(a[x] - a[i], a[x] - a[y]) != 0) return false;
    }
    return true;
}

bool solve(int x, int y){
    memset(vis, 0, sizeof vis);
    vis[x] = vis[y] = true;
    rep(i,0,n){
        if(cross(a[x] - a[i], a[x] - a[y]) == 0) vis[i] = true;
    }
    return check();
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    n = nxt();
    rep(i,0,n) a[i].F = nxt(), a[i].S = nxt();
    if(n <= 4) return cout << "YES\n", 0;
    if(solve(0, 1) || solve(1, 2) || solve(0, 2)) return cout << "YES\n", 0;
    cout << "NO\n";

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}