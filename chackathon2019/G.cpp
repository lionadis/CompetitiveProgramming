#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MOD = 1e9 + 7;
const ll dx[4] = { -1,1,0,0 };
const ll dy[4] = { 0,0,-1,1 };
const ll MAX = 2e5 + 50 ;
const ll oo = 1e16;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
long long gcd(long long  a, long long  b) { return (b == 0 ? a : gcd(b, a % b)); }
ll n , m , q , ans , sz , k , x , d; string s ;
vector < pair < ll , ll > > v ;




ll calc(ll lo , ll hi){

    ll best = 0 ;
    while(lo <= hi){
        ll mid = (lo + hi) >> 1 ;
        int nb  = 0 ;
        for(int i = 0 ; i < n ; ++i){
            ll sum =  v[i].s * d ;
            nb += sum / mid;
        }
        if(nb >= m){
            best = mid ;
            lo = mid + 1;
        }
        else
            hi = mid - 1 ;

    }

    return best ;
}

ll pw[10] ;
int main(){
   /* ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
*/
   int tc ;
   scanf("%d",&tc);

   while(tc--){
    int A , B ;
    scanf("%d%d",&A,&B);
   // cin >> A >> B ;
    ans = 0 ;

    pw[0] = 1;
    for(int i = 1 ; i < 10 ; ++i)
        pw[i] = pw[i - 1] * 10 ;

    for(int i = A ; i<= B ; ++i){
        string s = to_string(i) ;
        int sz = (int)s.length();
        int tmp = i ;
        for(int j = 0 ; j < sz ; ++j){

            tmp -= (int)(s[j]-'0')*pw[sz - 1];
            tmp *=10;
            tmp += (int)(s[j] - '0');
            cout << tmp << '\n';
            if(tmp > i && tmp <= B) ++ans;
        }


    }
    printf("%d\n",ans);
    //cout << ans << '\n';
   }

}

/*
5 10 1
2 8
4 6
8 5
9 4
14 2


*/
