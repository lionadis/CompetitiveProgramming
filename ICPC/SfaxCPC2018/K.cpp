#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MOD = 1e9 + 7 ;
#define pb push_back
#define all(v) v.begin(),v.end()
vector < vector  < ll > > g ;
ll p[101010];
ll pending[101010];
ll ans[101010];
bool vis[101010];

void dfs(int u,int parent)
{

    if(vis[u]) return ;
    vis[u] = true ;
    p[u] = parent ;

    for(auto v : g[u])
    if(!vis[v]) dfs(v,u);


}
signed main()
{
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    freopen("floor.in", "r", stdin);
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    ll ans =  0 , n ,T,m ;
    g.clear(); g.resize(101010);
    cin>>T ;
    while(T--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++) g[i].clear(),p[i]=-1,pending[i]=0,vis[i]=false;
        for(int i=0;i<n-1;i++)
        {

        ll l,r;
        cin>>l>>r;
        --l; --r;

        g[l].pb(r);
        g[r].pb(l);


        }

   // dfs(0,-1);

    while(m--)
    {
    ll op,u,x;

    cin>>op;

    if(op==1)
    {
        cin>>u;
        --u;
        ll ans = 0 ;
        for(auto v:g[u] ) ans+=pending[v];


        cout<<ans<<'\n';
    }
    else
    {
        cin>>u>>x;
        --u;
        pending[u]+=x;

    }



    }
    }

/*
1
6
1 2 3 3 2 1


*/

return 0 ;
}
