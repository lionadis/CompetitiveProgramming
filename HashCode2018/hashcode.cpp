#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define f_in freopen("e_high_bonus.in","r",stdin);
#define f_out freopen("e_high_bonus.out","w",stdout);
#define debug(x) cerr << #x << " : " << x << "\n";
#define _ cin.sync_with_stdio(0); cin.tie(0);
#define tl cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n"
#define Func {ans += solve(i); ++i;}
#define int ll

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
    for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc()); x*=f;
    return x;
}

struct Ride{
    int idx, x_start, y_start, x_end, y_end, t_start, t_end;
    int distance(){
        return (abs(x_end - x_start) + abs(y_start - y_end));
    }
};
const int N = 10010;
Ride rides[N];
int time_free[N];
vi ans[N];

int thresh_hold(Ride a){
    return a.t_end - a.distance();
}

bool compare_rides(const Ride& a, const Ride& b){
    return thresh_hold(a) < thresh_hold(b);
}

set<int> p;

main(){
    f_in;
    f_out;
    int rol = nxt(), col = nxt(), vehicule = nxt(), R = nxt(), B = nxt(), T = nxt();
    rep(i,0,vehicule){
        cout<<R/vehicule<<" ";
        rep(j,0,R/vehicule){
            cout<<(R/vehicule)*i+j << " " ;
        }
        cout<<"\n";
    }
}
