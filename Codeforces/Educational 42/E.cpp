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
#define debug(x) cerr << #x << " : " << x << "\n";
#define _ cin.sync_with_stdio(0); cin.tie(0);


typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

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

const int N = 200123;
ll a[N],c[N],d=0,e,f,g,b_start=0,b_end,r_start=0,r_end;
ll ans=0;
char city[N];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n;  
    cin >> n;
    rep(i,0,n) 
    {
        cin >> a[i] >> b[i];
        if (b[i]=='P') c[++d]=a[i];
        if (b[i]=='R')
        {
            if (!r_start) r_start=a[i];
            r_end=a[i];
        }
        if (b[i]=='B')
        {
            if (!b_start) b_start=a[i];
            b_end=a[i];
        }
    }
    if (d)
    {
    ll q1=1, q2=1, c1;
    ll l1, l2, p1,p2;
    rep(i,0,n)
    {
        if (b[i]=='B')
        {
            if(a[i]<c[1]&&q1)
            {
                q1=0;ans+=c[1]-a[i];
            }
            else if (a[i]>c[1])
            {
                l1=max(a[i]-p1,l1);
                p1=a[i];
            }
        }
        else if (b[i]=='R')
        {
            if(a[i]<c[1]&&q2)
            {
                q2=0;ans+=c[1]-a[i];
            }
            else if (a[i]>c[1])
            {
                l2=max(a[i]-p2,l2);
                p2=a[i];
            }
        }
        else if (a[i]==c[1]) l1=l2=0,p1=p2=c1=c[1];
            else 
            {
                l1 = max(a[i]-p1,l1);
                l2 = max(a[i]-p2,l2);
                if (l1+l2>a[i]-c1) ans += -l1-l2+3*(a[i]-c1);
                else ans+=2*(a[i]-c1);
                l1=l2=0;
                p1=p2=c1=a[i];
            }
            ans+=p1+p2-2*c[d];
            }
        else
        {
            if (b_start) ans+=b_end-b_start;
            if (r_start) ans+=r_end-r_start;
        }
    }
    cout<<ans;
}