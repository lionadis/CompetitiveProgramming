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

const int maxn = 100123;
const int lgn = 20;
ll a[maxn], f[maxn][lgn], ans;
vector<int> G[maxn];

void dfs(int u, int p, int x){
    int w = a[u] >> x & 1;
    f[u][w] = 1, f[u][w ^ 1] = 0;
    trav(v, G[u]){
        if(v != p){
            dfs(v, u, x);
            ans += (1 << x) * (f[u][1] * f[v][0]  + f[u][0] * f[v][1]);
            f[u][w] += f[v][0];
            f[u][w ^ 1] += f[v][1];
        }
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n;
    cin >> n;
    rep(i,0,n) cin >> a[i], ans += a[i];
    rep(i,0,n - 1){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }    
    rep(i,0,lgn) dfs(0, -1, i);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}