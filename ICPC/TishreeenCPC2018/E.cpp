#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define F first
#define S second
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

const int mod = (int) 1e9 + 7;
const int maxn = 123;
int dp[maxn][maxn];

int sum(int a, int b){
    return (a + b) % mod;
}

ll solve(int curr, int left){
    if(left == 0) return (curr != 0);
    int &res = dp[curr][left];
    if(res != -1) return res;
    res = 0;
    rep(k,1,left+1){
        res = sum(res, solve(curr ^ k, left - k));
    }
    return res;
}

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t;
    cin >> t;
    memset(dp, -1, sizeof dp);
    while(t--){
        int n;
        cin >> n;
        cout << solve(0, n) << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}