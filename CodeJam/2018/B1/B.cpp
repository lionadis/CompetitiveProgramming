#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define f_in freopen("test.in","r",stdin);
#define f_out freopen("test.in","w",stdout);
#define dbg(x) cerr << #x << " : " << x << "\n";
#define _ cin.sync_with_stdio(0); cin.tie(0);


inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}

template<typename T = int>
inline T nxt(){
    char c=nc();T x=0; int f=1;
    for(;c>'9'||c<'0';c=nc())if(c=='-')f=-1;
    for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc());
    x*=f;
    return x;
}

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

ll maxSize,maxNum,tmp,lasth,lastm,x,y,z,r,l,k,a,h,s,M,N ; char c ;
vector < ll > v ;

ll di[101010],ai[101010],bi[101010],mi[101010],ni[101010];

ll solve(ll M, ll N, bool MF, bool NF, ll i, ll s){
    if(i == s-1) return 1;
    ll sum = i+1;
    for(sum = i+1;sum<s;sum++){
        if(MF && mi[sum] == M) continue;
        if(NF && ni[sum] == N) continue;
        
        if(!MF){
            MF = true,M = mi[sum];
            continue;
        }
        if(!NF){
            NF = true,N = ni[sum];
            continue;
        }
        break;
    }
    return sum-i;
}




int main()
{
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
int T;
cin>>T;
rep(t,1,T+1)
{
cin>>s;

rep(i,0,s) cin>>di[i]>>ai[i]>>bi[i],mi[i] = di[i] + ai[i],ni[i] = di[i] - bi[i];
    		
    		 maxSize = 0;
    		 maxNum = 0;
    		for(ll i=0;i<s;i++){
    			 M = mi[i];  N = ni[i];
    			ll ans = max(solve( M, N, true, false, i, s), solve( M, N, false, true, i, s));
    			if(ans > maxSize) maxSize = ans,maxNum = 1;
    			else if(ans == maxSize) maxNum++;
    		}


cout<<"Case #"<<t<<": "<<maxSize<<" "<<maxNum;
cout<<"\n";
}


return 0 ;
}
