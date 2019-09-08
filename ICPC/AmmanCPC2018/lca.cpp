#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll order[300008], dis1[100008], dis2[100008], depth[100008], firstocc[200008],
    vis[100008], spt[200008][30];
ll n, o = 0, u, v, l, r, c1, c2;
ll root = 0, sum = 0;
std::vector<std::vector<pair<ll, pair<ll, ll>>>> adj;
// TODO
void dfs(ll cur, ll dep) {
  firstocc[cur] = o;
  order[o] = cur;
  depth[o++] = dep;
  vis[cur]++;
  for (auto e : adj[cur]) {
    v = e.first;
    if (vis[v])
      continue;
    dis1[v] = dis1[cur] + e.second.first;
    dis2[v] = dis2[cur] + e.second.second;
    dfs(v, dep + 1);
    order[o] = cur;
    depth[o++] = dep;
  }
}
void build_sparse_table() {
  for (ll i = 0; i < 2 * n - 1; i++)
    spt[i][0] = i;
  for (ll j = 1; (1 << j) <= 2 * n - 1; j++)
    for (ll i = 0; i + (1 << j) - 1 < 2 * n - 1; i++)
      if (depth[spt[i][j - 1]] < depth[spt[i + (1 << (j - 1))][j - 1]])
        spt[i][j] = spt[i][j - 1];
      else
        spt[i][j] = spt[i + (1 << (j - 1))][j - 1];
}
ll rmq(ll l, ll r) {
  ll k = (ll)floor(log(1.0 * (double)r - l + 1) / log(2.0) * 1.0);
  if (depth[spt[l][k]] < depth[spt[r - (1 << k) + 1][k]])
    return spt[l][k];
  return spt[r - (1 << k) + 1][k];
}
ll lca(ll u, ll v) {
  if (firstocc[v] < firstocc[u])
    swap(u, v);
  return order[rmq(firstocc[u], firstocc[v])];
}
ll dist_from_root1(ll v) { return dis1[v]; }
ll dist_from_root2(ll v) { return dis2[v]; }
ll dist1(ll u, ll v) {
  return dist_from_root1(u) + dist_from_root2(v) - dist_from_root1(lca(u, v)) -
         dist_from_root2(lca(u, v));
}
int main() {
    freopen("test.in", "r", stdin);
  ll t = 1;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  //std::cin >> t;
  int test_case=1;
  while (t--) {
    sum = 0;
    o = 0;
    std::cin >> n;
    memset(vis, 0, sizeof(vis));
    memset(order, 0, sizeof(order));
    memset(depth, 0, sizeof(depth) );
    memset(firstocc, 0, sizeof(firstocc) );
    memset(dis1, 0, sizeof(dis1));
    memset(dis2, 0, sizeof(dis2));
    memset(spt, 0, sizeof(spt) );
    adj = std::vector<std::vector<pair<ll, pair<ll, ll>>>>(n + 5);
    for (ll i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, {1, 2}});
        adj[v].push_back({u, {1, 2}});
    }
    dfs(root, 0);
    build_sparse_table();
    ll q;
    cin >> q;
    while (q--) {
      std::cin >> l >> r;
      --l, --r;
      int u = lca(l, r);
      if(dis1[l] < dis1[r]) cout << "NO\n";
      else cout << "YES " << u + 1 << '\n';
    }
  }
}