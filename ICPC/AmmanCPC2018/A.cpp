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
int cost[N];
pii a[N];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int t = nxt();
    while(t--){
        int n = nxt(), k = nxt();
        rep(i,0,n){
            a[i] = {nxt(), nxt()};
            cost[i] = nxt();
        }
        sort(a, a + n);
        int L = a[0].F, R = a[0].F, L_idx = 0, R_idx = 0;
        ll curr_ans = 0, ans = 0;
        while(R_idx < n){
            while(a[R_idx].R - L < k && R_idx < n) curr_ans += 1LL * (a[R_idx].S - a[R_idx].F + 1) * cost[R_idx], R_idx++;
            curr_ans -= 1LL * (a[R_idx].S - a[R_idx].F + 1) * cost[R_idx];
            if(a[R_idx].L - L >= k){
                ans = max(curr_ans, ans);
                L_idx++;
                L = a[L_idx].F;
            }
            else {
                if(cost[L_idx] > cost[R_idx]){
                    
                }
            }


        }
    }
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}