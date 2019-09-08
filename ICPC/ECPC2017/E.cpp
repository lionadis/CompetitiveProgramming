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
int sz[maxn], spf[maxn], cnt[3], cnt_primes[maxn], calls, one;
bool vis[maxn];
ll ans;
vector<int> fact[maxn];
vector<vector<pii>> G;

void sieve(){
    spf[1] = 1;
    rep(i,0,maxn) spf[i] = i;
    for(int i = 2; i < maxn;i += 2 ) spf[i] = 2;
    for(int i = 3; i * i < maxn; ++i){
        if(spf[i] == i) {
            for(int j = i * i; j < maxn; j += i) if(spf[j] ==  j) spf[j] = i;
        }
    }
    rep(i,2,maxn){
        int x = i;
        while(x != 1){
            fact[i].push_back(spf[x]);
            x /= spf[x];
        }
    }
}

void dfs_sz(int u, int p){
    sz[u] = 1;
    trav(e, G[u]){
        int v = e.F;
        if(v != p) dfs_sz(v, u), sz[u] += sz[u];
    }
}

int centroid(int u){    
    trav(e, G[u]){
        int v = e.F;
        if(!vis[v] && sz[v] > sz[u] / 2){
            sz[u] -= sz[v];
            sz[v] += sz[u];
            return centroid(v);
        }
    }
    return u;
}

void solve(int p1, int p2){
    // cout << "start solve\n";
    if(p1 == -1) ans += cnt[2];
    else if(p2 == -1) ans += cnt[1], ans -= cnt_primes[p1];
    else ans += cnt[0];
    // cout << "end solve\n";
}

void inc(int p1, int p2){
    // cout << "start inc\n";
    if(p1 == -1) cnt[0]++;
    else if(p2 == -1) cnt[1]++, cnt_primes[p1] += one;
    else cnt[2]++;
    // cout << "end inc\n";
}

void dfs(int u, int p, int p1, int p2, int op){
    (op) ? solve(p1, p2): inc(p1, p2);
    trav(e, G[u]){
        int v = e.F, w = e.S;
        if(v != p && !vis[v]){
            if(sz(fact[w]) > 2) continue;
            else if(sz(fact[w]) == 2){
                if(p1 != -1 || fact[w][0] == fact[w][1]) continue;
                dfs(v, u, fact[w][0], fact[w][1], op);
            }
            else if(sz(fact[w]) == 1){
                if(p2 != -1 || p1 == w) continue;
                dfs(v, u, p1, w, op);
            }
            else dfs(v, u, p1, p2, op);
        }
    }
}

void decompose(int u){
    u = centroid(u);
    vis[u] = 1;
    memset(cnt, 0, sizeof cnt);
	one = 1;
    trav(e, G[u]){
        int v = e.F, w = e.S;
        if(!vis[v]){
            if(sz(fact[w]) > 2) continue;
            if(sz(fact[w]) == 2){
                if(fact[w][0] == fact[w][1]) continue;
                dfs(v, v, fact[w][0], fact[w][1], 1), dfs(v, v, fact[w][0], fact[w][1], 0);
            } 
            else if(sz(fact[w]) == 1) dfs(v, v, w, -1, 1), dfs(v, v, w, -1, 0);
            else  dfs(v, v, -1, -1, 1), dfs(v, v, -1, -1, 0);
        }
    }
    solve(-1, -1);
	one = -1;
    trav(e, G[u]){
        int v = e.F, w = e.S;
        if(!vis[v]){
            if(sz(fact[w]) > 2) continue;
            if(sz(fact[w]) == 2){
                if(fact[w][0] == fact[w][1]) continue;
                dfs(v, v, fact[w][0], fact[w][1], 0);
            } 
            else if(sz(fact[w]) == 1) dfs(v, v, w, -1, 0);
            else  dfs(v, v, -1, -1, 0);
        }
	}
    trav(e, G[u]){
        int v = e.F;
        if(!vis[v]) decompose(v);
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
	freopen("evaluations.in", "r", stdin);
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int t;
    cin >> t;
    sieve();
	t = 10;
    rep(T, 1, t + 1){
        int n;
        cin >> n;
        G.clear();
        G.resize(n);
        memset(vis, 0, sizeof vis);
        memset(sz, 0, sizeof sz);
        ans = 0;
        rep(i,0,n - 1){
            int u, v, w;
            cin >> u >> v >> w;
            --u, --v;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        dfs_sz(0, 0);
		decompose(0);
        cout << "Case " << T << ": " << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
