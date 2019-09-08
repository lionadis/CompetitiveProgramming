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

int T,N,D,d,md;
bool vis[222];
int likes[222];
int main(){
    cin>>T;
    while(T--){
        cin>>N;
        memset(vis,false,sizeof vis);
        memset(likes,0,sizeof likes);
        while(N--){
            cin>>D;
            if(D == -1)exit(0);
            md = -1;
            for(int j=0;j<D;j++){
                cin>>d;
                if(vis[d])continue;
                if(md == -1)md = d;
                else if(likes[d] < likes[md])md = d;
                likes[d]++;
            }
            if(md != -1)vis[md]=true;
            cout<<md<<endl;
            cout<<flush;
        }

    }
}