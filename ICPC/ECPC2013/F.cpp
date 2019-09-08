#include <bits/stdc++.h>

#define rep(i,a,b) for(int i=a;i<(b);++i)
#define F first
#define S second
#define sz(a) (a).size()
#define  ll long long

using namespace std;
const int maxn = 112;
int a[maxn], ans[maxn];
ll n;
bool is_less(ll k){
    return k*(2*k+1)*(k+1)<=6*n;
}
bool is_less2(ll k){
    return k*(k+1)<2*n;
}
bool is_less3(ll k){
    return k*(k+1)<=2*n;
}

int main(){
    //freopen("cubes.in", "r+",stdin);
    freopen("army.in", "r+",stdin);
    ll t, tc = 0;
    cin >> t;
    while(t--){
        cin>>n;
        cout << "Case " <<++tc << ": ";
        ll l=0,r=3e6+9;
        while(l<r){
            ll mid=(l+r+1)/2;
            if(is_less(mid))l=mid;
            else r=mid-1;
        }
        ll k=l;
        n-=(k*(2*k+1)*(k+1))/6;
        ll cur=1;
        ll nb=k*k;
        if(!n){cout<<nb<<"\n"; continue;}
//        cout<<"first nb="<<nb<<"\n";
        k++;
//        cout<<"n= "<<n<<endl;
        ll first_sum=(k*(k+1))/2;
        if(n<=first_sum){
            ll l=0,r=3e6+9;
            while(l<r){
                ll mid=(l+r+1)/2;
                if(is_less2(mid))l=mid;
                else r=mid-1;
            }
            ll x=1+l;
            nb+=x;
        }
        else{
            n-=first_sum;
            nb+=k;
            k--;
            n=(k*(k+1))/2-n;

            ll l=0,r=3e6;
            while(l<r){
                ll mid=(l+r+1)/2;
                if(is_less3(mid))l=mid;
                else r=mid-1;
            }
            ll x=l;

//            long double delta=sqrt(1+8*X);
//            ll x=floor((delta-1)/2);
            nb+=k-x;
        }

        cout<<nb;




         cout << '\n';

    }
}
