#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define maxn 100000
#define P 1000000007
#define pi  3.1415926535
#define Max(a,b) (((a)>(b))?(a):(b))
#define Min(a,b) (((a)<(b))?(a):(b))
#define me(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
inline void up(int&x,int y){x=x+y<P?x+y:x+y-P;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll a[300100],c[300010],d=0,e,f,g,bs=0,be,rs=0,re;
ll ans=0;
char b[300100];
int main()
{
    //freopen("stdin.txt","r",stdin);
    //freopen("stdout.txt","w",stdout);
    //clock_t time=clock();
    //srand(time(NULL));
    cin>>e;
    for (int i=1;i<=e;i++) 
    {
        scanf("%lld %c",&a[i],&b[i]);
        if (b[i]=='P')
        {
            c[++d]=a[i];
        }
        if (b[i]=='R')
        {
            if (!rs) rs=a[i];
            re=a[i];
        }
        if (b[i]=='B')
        {
            if (!bs) bs=a[i];
            be=a[i];
        }
    }
    if (d)
    {
    ll q1=1,q2=1,c1;
    ll l1,l2,p1,p2;
    for (int i=1;i<=e;i++) 
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
        l1=max(a[i]-p1,l1);
        l2=max(a[i]-p2,l2);
        if (l1+l2>a[i]-c1) ans+=-l1-l2+3*(a[i]-c1);
        else ans+=2*(a[i]-c1);
        l1=l2=0;
        p1=p2=c1=a[i];
    }
    ans+=p1+p2-2*c[d];
}
    else
    {
        if (bs) ans+=be-bs;
        if (rs) ans+=re-rs;
    }
    cout<<ans;

    return 0; 
}
close