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

const int N = 100123;
int s[N], e[N];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n = nxt(), m = nxt(), cs = nxt(), ce = nxt(), v = nxt();
    rep(i,0,cs) s[i] = nxt();
    rep(i,0,ce) e[i] = nxt();
    int q = nxt();
    while(q--){
        int ys = nxt(), xs = nxt(), ye = nxt(), xe = nxt();
        if(ye == ys){
            cout << abs(xs  - xe) << '\n';
            continue; 
        }
        int ans = 1e9, curr_ans = 0;
        // Using stairs
        if(cs){
            int idx = lower_bound(s, s + cs, xs) - s;
            curr_ans = 0;
            curr_ans += abs(xs - s[idx]);
            curr_ans += abs(s[idx] - xe);
            curr_ans += abs(ys - ye);
            ans = min(curr_ans, ans);
            if(idx){
                curr_ans = 0;
                curr_ans += abs(xs - s[idx - 1]);
                curr_ans += abs(s[idx - 1] - xe);
                curr_ans += abs(ys - ye);
                ans = min(curr_ans, ans);
            }
        }
        //Using elevators
        if(ce){
            int idx = lower_bound(e, e + ce, xs) - e;
            curr_ans = 0;
            curr_ans += abs(xs - e[idx]);
            curr_ans += abs(e[idx] - xe);
            curr_ans += abs(ys - ye) / v;
            if(abs(ys - ye) % v) curr_ans++;
            ans = min(curr_ans, ans);
            if(idx){
                curr_ans = 0;
                curr_ans += abs(xs - e[idx - 1]);
                curr_ans += abs(e[idx - 1] - xe);
                curr_ans += abs(ys - ye) / v;
                if(abs(ys - ye) % v) curr_ans++;
                ans = min(curr_ans, ans);
            }
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}