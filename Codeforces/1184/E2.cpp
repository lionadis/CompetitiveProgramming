//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
vector<pair<pair<int,int> ,  pair<int,int> > > edges;
int par[202020], rnk[202020];
int find(int x){
    return ((par[x] == x) ? x : par[x] = find(par[x]));
}
bool merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)return false;
    if(rnk[x] > rnk[y])par[y] = x;
    else{
        par[x] = y;
        if(rnk[x] == rnk[y])rnk[x]++;
    }
    return true;
}
bool in_mst[202020];
vector<pair<int, int> > mst[202020];
int lvl[202020];
int dp_lca[202020][20], dp_mx[202020][20];
long long int result[202020];
void dfs(int u, int p){
    for(int i=1;i<20;i++){
        dp_lca[u][i] = dp_lca[dp_lca[u][i-1]][i-1];
        dp_mx[u][i] = max(dp_mx[u][i-1], dp_mx[dp_lca[u][i-1]][i-1]);
    }
    for(int i=0;i<(int)mst[u].size();i++){
        int v = mst[u][i].first;
        int w = mst[u][i].second;
        if(v != p){
            dp_lca[v][0] = u;
            dp_mx[v][0] = w;
            lvl[v] = lvl[u] + 1;
            dfs(v, u);
        }
    }
}
int lca_need(int u, int v){
    if(lvl[u] > lvl[v])swap(u, v);
    int result = 0;
    for(int i=19;i>=0;i--){
        if(lvl[v] - (1<<i) >= lvl[u]){
            result = max(result, dp_mx[v][i]);
            v = dp_lca[v][i];
        }
    }
    if(u == v)return result;
    for(int i=19;i>=0;i--){
        if(dp_lca[u][i] != dp_lca[v][i]){
            result = max(result, dp_mx[u][i]);
            result = max(result, dp_mx[v][i]);
            u = dp_lca[u][i];
            v = dp_lca[v][i];
        }
    }
    result = max(result, dp_mx[u][0]);
    result = max(result, dp_mx[v][0]);
    return result;
}
int main(){
    //freopen("test.in", "r+", stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++)par[i] = i;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--, v--;
        edges.push_back(make_pair(make_pair(w, i), make_pair(u, v)));
    }
    sort(edges.begin(), edges.end());
    for(int i=0;i<m;i++){
        int u = edges[i].second.first, v = edges[i].second.second, w = edges[i].first.first;
        if(merge(u, v)){
            in_mst[i] = true;
            mst[u].push_back(make_pair(v, w));
            mst[v].push_back(make_pair(u, w));
        }
    }
    dfs(0, -1);
    for(int i=0;i<m;i++){
        if(in_mst[i])result[edges[i].first.second] = -1;
        else{
            int u = edges[i].second.first, v = edges[i].second.second;
            result[edges[i].first.second] = lca_need(u, v);
        }
    }
    for(int i=0;i<m;i++){
        if(result[i] != -1)
            cout<<result[i]<<"\n";
    }
}
