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

const int maxn = 100123;
int cnt[maxn], d[maxn];

vector<vi> G;

void dfs(int u, int p = -1){
    cnt[u] = 1;
    d[u] = p;
    trav(v, G[u]){
        if(v != p){
            dfs(v, u);
            cnt[u] += cnt[v];
        }
    }
}



int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        a--, b--;
        G.clear(), G.resize(n);
        rep(i,0,n - 1){
            int u, v;
            cin >> u >>  v;
            u--, v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(a);
        ll ans = 0;
        int last = 0;
        while(a != b){
            ans += 1LL * (cnt[b] - last) * (n - cnt[b]);
            last = cnt[b];
            b = d[b];
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}