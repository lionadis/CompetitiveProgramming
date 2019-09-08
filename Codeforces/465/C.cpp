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
#define tl cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n"
#define Func {ans += solve(i); ++i;}


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

int main(){
#ifndef ONLINE_JUDGE
    f_in
#else
    _
#endif
    int R, x1, y1, x2, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;
    ll pos = 1LL*(x2-x1)*(x2-x1) + 1LL*(y2-y1)*(y2-y1);
    if(pos >= 1LL*R*R){
        cout << x1 << " " << y1 << " " << R << '\n';
        return 0;
    }
    if(x1 == x2 && y1 == y2){
        cout << x1 << " " << 1.0*y1-1.0*R/2 << " " << 1.0*R/2 << '\n';
        return 0;
    }
    double d = sqrt(pos);
    double r_ans = (d + R)/2;
    double vx = (x1-x2) / d, vy = (y1-y2) / d;
    double x_ans = x2 + vx * r_ans, y_ans = y2 + vy * r_ans;
    cout << fixed << setprecision(7) << x_ans << " " << y_ans << " " << r_ans << '\n';
}
