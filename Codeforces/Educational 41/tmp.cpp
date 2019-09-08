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

int const maxn=1e5+5;
struct node{
    int x,y;
}a[maxn],b[maxn];
int vis[maxn];
int main(){
    
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int cnt=1,n;
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    scanf("%d%d",&a[i].x,&a[i].y);
    if(n<=4) cout << "YES\n";
    else{
        int check=0,test=0,xx;
        double k1,b1,k2,b2;
        for(int i=1;i<=3;i++)
        for(int j=i+1;j<=4;j++)
        for(int k=j+1;k<=5;k++)
        if(a[i].x==a[j].x&&a[j].x==a[k].x){
            test=1;
            check=1;
            xx=a[i].x;
            break;
        }
        else if((a[i].y-a[j].y)*(a[k].x-a[j].x)==(a[i].x-a[j].x)*(a[k].y-a[j].y)){
            test=1;
            k1=(double)(a[i].y-a[j].y)/(a[i].x-a[j].x);
            b1=a[i].y-a[i].x*k1;
        }
        if(!test) cout << "NO\n";
        else{
            if(check){
                for(int i=1;i<=n;i++)
                if(a[i].x!=xx){
                    b[cnt].x=a[i].x;
                    b[cnt++].y=a[i].y;
                }
            }
            else{
                for(int i=1;i<=n;i++)
                if(a[i].y!=a[i].x*k1+b1){
                    b[cnt].x=a[i].x;
                    b[cnt++].y=a[i].y;
                }
            }
            if(cnt<=2) cout << "YES\n";
            else{
                if(b[1].x==b[2].x){
                    for(int i=3;i<cnt;i++)
                    if(b[i].x!=b[1].x){
                        test=0;
                        break ;
                    }
                }
                else{
                    k2=double(b[1].y-b[2].y)/(b[1].x-b[2].x);
                    b2=b[1].y-k2*b[1].x;
                    for(int i=3;i<cnt;i++)
                    if(b[i].y!=k2*b[i].x+b2){
                        test=0;
                        break ;
                    }
                }
                if(test) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
}