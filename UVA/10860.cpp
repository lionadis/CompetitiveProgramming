#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define f_in freopen("test.in","r",stdin);
#define f_out freopen("test.out","w",stdout);
#define debug(x) cerr << #x << " : " << x << "\n";
#define _ cin.sync_with_stdio(0); cin.tie(0);
#define tl cerr <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n"
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
    for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc());
    x*=f;
    return x;
}

const int N = (int) 1e4 + 123;
unordered_map<string, bool> a;
string s;
int dp[N];

int solve(int idx){
    if(idx == sz(s)) return 0;
    int &ans = dp[idx];
    if(~ans) return ans;
    ans = 1e9;
    string tmp;
    rep(i,0,100){
        tmp += s[i + idx];
        if(a[tmp]) ans = min(ans, 1 + solve(idx + i + 1));
    }
    return ans;
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
    f_out
#else
    _
#endif
    int t;
    cin >> t;
    rep(test_case,1,t + 1){
        a.clear();
        memset(dp, -1, sizeof dp);
        cin >> s;
        int n;
        cin >> n;
        rep(i,0,n){
            string x;
            cin >> x;
            a[x] = true;
            reverse(all(x));
            a[x] = true;
        }
        int ans = solve(0);
        cout << "Set " << test_case << ": ";
        if(ans >= 1e9) cout << "Not possible.\n";
        else          cout << ans << ".\n";
    }
}