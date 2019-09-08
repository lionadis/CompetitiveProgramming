#include<bits/stdc++.h>
 
using namespace std;
 
#define For(i, a, b) for(int i = a; i <= b; ++ i)
#define ll long long
#define pb push_back
 
const int N = 5e4 + 5;
 
int n, dem, Max, child[N], all[N], calls;
long double ans;
vector < int > adj[N], prime;
bool used[N], vis[N];
 
void snt(){
    used[0] = used[1] = true;
    For(i, 2, n - 1) if(!used[i]){
        for(ll j = 1ll*i*i; j < n; j += i) used[j] = true;
        prime.pb(i);
    }
}
void dfs(int u, int p){
    child[u] = 1;
    for(int v : adj[u]) if(v != p && !vis[v]) dfs(v, u), child[u] += child[v];
}
int findcen(int u, int p, int sz){
    for(int v : adj[u]) if(v != p && !vis[v] && child[v] > sz / 2) return findcen(v, u, sz);
    return u;
}
int solve(int h, int lim, int id){
    calls++;
    int res = 0;
	for(int i : prime){
        // if(i > lim) break;
        if(i >= h) res += all[i - h];
    }
    return res;
}
void dfs1(int u, int p, int id, int h, int type){
	Max = max(Max, h);
    (type) ? ans += solve(h, Max << 1, id) : all[h] ++;
    for(int v : adj[u]) if(v != p && !vis[v]) dfs1(v, u, id, h + 1, type);
}
void centroid(int root){
    dfs(root, root);
    // if(child[root] == 1) return;
    int cen = findcen(root, root, child[root]);
    vis[cen] = true; Max = 0;
    memset(all, 0, sizeof all);
    for(int v : adj[cen]) if(!vis[v]) dfs1(v, v, cen, 1, 1), dfs1(v, v, cen, 1, 0);
    ans += solve(0, Max << 1, 0);
    for(int v : adj[cen]) if(!vis[v]) centroid(v);
}
signed main(){
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    scanf("%d",&n); snt();
    cout << prime.size() << '\n';
    For(i, 1, n - 1){
        int u, v; scanf("%d%d",&u, &v);
        adj[u].pb(v); adj[v].pb(u);
    }
    centroid(1);
    cout << calls << '\n';
    cout << fixed << setprecision(10) << ans / ((n + .0) * (n - 1 + .0) / 2) << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}