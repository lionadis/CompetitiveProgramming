#include <bits/stdc++.h>
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define _ cin.sync_with_stdio(0);cin.tie(0);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define ii pair<int,int>
#define hell 1000000007
#define rep(i, a, b) for (int i = a; i<(int)b; i++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define in freopen("galactic.in","rt",stdin)
#define out freopen("test.out","wt",stdout)
#define fi first
#define se second
#define endl "\n"
#define MOD ((ll)(1e9+7))
using namespace std;

ll fact[100123];

ll pw(ll a, ll e) {
    if (e == 0) return 1;
    ll x = pw(a * a % MOD, e >> 1);
    return e & 1 ? x * a % MOD : x;
}

ll mul(ll a, ll b){
    return (a * b) % MOD;
}

ll c(int n, int k){
    return mul(fact[n], pw(mul(fact[k],fact[n - k]), MOD - 2));
}

int main(){
    _
    #ifndef ONLINE_JUDGE
        in;
    #endif
    freopen("galactic.in","rt",stdin);
    fact[0] = 1;
    for(int i=1;i<100123;++i) fact[i] = (fact[i - 1] * i) % MOD; 
    int t; cin>>t;
    while(t--){
        int n,k;
        cin>>n >>k;
        if(k>n){
            cout<< 0;
            continue;
        }
        ll res=1,kpn=1,npn=1;
        for(ll i=0; i<=k;++i){
            if(i%2)
                res-=(c(k,k-i)*pw(k-i,n))%MOD;
            else
                res+=(c(k,k-i)*pw(k-i,n))%MOD;
        }
        cout<<res-1<<endl;






    }






















    return 0;
}
