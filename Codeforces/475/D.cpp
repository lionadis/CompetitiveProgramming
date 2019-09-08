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

const int N = 200123;
int cnt[N];
vi G[N];

void dfs_even(int u, int p){
    cnt[u] = 1;
    trav(v, G[u]){
        if(v != p){
            dfs_even(v, u);
            cnt[u] += cnt[v];
            if(cnt[v] % 2 == 0) cout << v + 1 << '\n';
        }
    }
}

void dfs_odd(int u, int p){
    if(cnt[u] % 2 == 1) cout << u + 1 << '\n';
    trav(v, G[u]){
        if(v != p) dfs_odd(v, u);
    }
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n = nxt();
    rep(i,0,n){
        int x = nxt() - 1;
        if(x == -1) continue;
        G[i].push_back(x);
        G[x].push_back(i);
    }
    if(n % 2 == 0) return cout << "NO\n", 0;
    cout << "YES\n";
    dfs_even(0, -1);
    dfs_odd(0, -1);
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}