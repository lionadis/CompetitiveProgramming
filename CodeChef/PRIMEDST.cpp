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
typedef vector<double> vd;

const int maxn = 50123;
int sz[maxn], cnt[maxn], calls, max_depth;
bool vis[maxn];
vi G[maxn], primes;
ll ans, n;

bitset<maxn> is_prime;
void sieve(){
    is_prime.set(), is_prime[0] = is_prime[1] = 0;
    for(int i = 4; i < maxn; i += 2) is_prime[i] = 0;
    for(int i = 3; i * i <= maxn; i += 2){
        if(is_prime[i]){
            for(int j = i*i; j < maxn; j += 2 * i) is_prime[j] = 0;
        }
    }
    rep(i,2,maxn) if(is_prime[i]) primes.push_back(i);
}



void dfs(int u, int p){
    sz[u] = 1;
    trav(v, G[u]){
        if(v != p) dfs(v, u), sz[u] += sz[v];
    }
}

int centroid(int u){
    trav(v, G[u]){
        if(!vis[v]  && sz[v] > sz[u] / 2){
            sz[u] -= sz[v];
            sz[v] += sz[u];
            return centroid(v);
        }
    }
    return u;
}

void solve(int h){
    calls++;
    trav(p, primes){
        if(p - h > max_depth) break;
        if(p >= h) ans += cnt[p - h];
    }
}

void dfs1(int u, int p, int h, int op){
    max_depth = max(h, max_depth);
    if(op) cnt[h] ++;
    else solve(h);
    trav(v, G[u]) if(p != v && !vis[v]) dfs1(v, u, h + 1, op);
}

void decompose(int u){
    u = centroid(u);
    vis[u] = true;
    memset(cnt, 0, sizeof cnt);
    max_depth = 0;
    trav(v, G[u]) if(!vis[v]) dfs1(v, v, 1, 0), dfs1(v, v, 1, 1);
    solve(0);
    trav(v, G[u]){
        if(!vis[v]) decompose(v);
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    cin >> n;
    sieve();
    rep(i,0,n - 1){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0, 0);
    decompose(0);
    cout << fixed << setprecision(10) << 1.0 * ans / (n * (n - 1) / 2) << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}