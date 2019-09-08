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

const int maxn = 16;
int a[maxn], dp[1 << maxn], n;

int solve(int mask){
    int &ans = dp[mask];
    if(ans != -1) return ans;
    ans = 0;
    rep(i,0, n){
        if(((1 << i) & mask) == 0){
            rep(j,i + 1,n){
                if(((1 << j) & mask) == 0){
                    rep(k,j + 1, n){
                        if(((1 << k) & mask) == 0){
                            ans = max(ans, (a[i] + a[j] + a[k] >= 20 ? 1 : 0) + solve(mask | 1 << i | 1 << j | 1 << k));
                        }
                    }
                }
            }
        } 
    }
    return ans;
}

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int tc = 1;
    while(n = nxt(), n){
        rep(i,0,n) a[i] = nxt();
        memset(dp, -1, sizeof dp);
        cout << "Case " << tc++ << ": "<< solve(0) << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
#endif
}