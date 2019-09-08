 #include <bits/stdc++.h>
 #define rep(i,a,b) for (int i=a;i<b;i++)
 #define rep2(i,a,b) for (int i=a;i>=b;i--)
 #define mod 1000000007
 #define INF  0x3f3f3f3f3f3f3f3f
 #define f first
 #define s second
 #define endl '\n'
 #define ll long long
 #define ii pair <int,int>
 #define pll pair <ll,ll>
 #define vi vector <int>
 #define vl vector <ll>
 #define vvi vector < vi >
 #define vii vector < ii >
 #define vvii vector < vii>
 #define vll vector < ll >
 #define vb  vector <bool>
 #define pb push_back
 #define mk make_pair
 #define sz(a) a.size()
 #define all(a) a.begin(),a.end()
 #define rall(a) a.rbegin(),a.rend()
 #define debug(x) cerr << #x << " is " << x << endl;
 #define input freopen("input","r",stdin)
 #define output freopen("output","w",stdout)
 #define fastIO ios_base::sync_with_stdio (0),cin.tie(0)
 
 using namespace std;
 void affiche (int t[],int n){ rep (i,0,n) cout<<t[i]<<" ";cout<<endl;}
 void afficheV (vi t){rep (i,0,sz(t))cout<<t[i]<<" ";cout<<endl;}
 
 int const MAXN=100;
 ll sum[MAXN];
 ll t[MAXN];
 int n,kk;
 ll dp[MAXN][MAXN][MAXN];
 ll x=1;
 ll solve (int i,int l,int k){
     if (i==n){
          if (kk==k) {
            return x-1;
          }
          return 0;
     }
     ll& ret=dp[i][l][k];
    if (ret!=-1) return ret;
    ll  s=sum[i+1]-sum[l];
    ret= solve (i+1,i+1,k+1)&s;
    if (i!=n-1)
         ret=max(ret,solve(i+1,l,k));
    return ret;
 }
 
 int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    _
#endif
    fastIO;
    int T;
    cin >> T;
    while(T--){
        rep(i,0,62){
            x*=2;
        }
        int id;
        cin>>n>>kk>>id;
        cout << id << '\n';
        memset(dp,-1,sizeof dp);
        sum[0]=0;
        rep(i,0,n){
            cin>>t[i];
            sum[i+1]=sum[i]+t[i];
        }
        cout<<solve(0,0,0) << '\n';
    }
 
 }