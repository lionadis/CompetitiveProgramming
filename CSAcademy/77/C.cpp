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

const int N = 100123;
int a[N][2], n;
ll dp[N][2][2][2];

ll solve(int idx, int row, int p, int prev){
    if(idx == n && p) return -1e9;
    if(idx == n && !p) return 1e9;
    if(idx == n - 1 && row == 1) return a[idx][row];
    ll &ans = dp[idx][row][p][prev];
    if(~ans) return ans;
    ans = a[idx][row];
    if(p == 0){
        if(prev == 0) ans +=  max(solve(idx, 1 - row, 1 - p, 1), solve(idx + 1, row, 1 - p, 0));
        else ans += solve(idx + 1, row, 1 - p, 0);
    }   
    else {
        if(prev == 0) ans +=  min(solve(idx, 1 - row, 1 - p, 1), solve(idx + 1, row, 1 - p, 0));
        else ans += solve(idx + 1, row, 1 - p, 0);
    }
    return ans;

}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    n = nxt();
    rep(i,0,n) a[i][0] = nxt();
    rep(i,0,n) a[i][1] = nxt();
    memset(dp, -1, sizeof dp);
    cout << solve(0,0,1,0) << '\n';

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}