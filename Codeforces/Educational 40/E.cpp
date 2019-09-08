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
int v[N], t[N];
pii a[N];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n = nxt(), T = nxt();
    double curr_T = 0, s = 0;
    bool t1 = false, t2 = false;
    rep(i,0,n) v[i] = nxt();
    rep(i,0,n) t[i] = nxt(), t1 = (t1 || t[i] >= T), t2 = (t2 || t[i] <= T);
    rep(i,0,n) a[i] = {t[i], v[i]}, s += v[i], curr_T += 1LL * v[i] * t[i];
    if(!t1 || !t2) return cout << 0 << '\n', 0;
    curr_T /= s;
    sort(a, a + n);
    if(curr_T > T) reverse(a, a + n);
    int idx = 0;
    while(idx < n){
        if(T == a[idx].F) break;
        double x = s * (T - curr_T) / (T - a[idx].F);
        if(x <= a[idx].S){
            s -= x;
            break;
        }
        curr_T = (curr_T * s - 1LL * a[idx].F * a[idx].S) / (s - a[idx].S);
        s -= a[idx].S;
        idx ++;
    }
    cout << fixed << setprecision (10) << s << '\n';
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}