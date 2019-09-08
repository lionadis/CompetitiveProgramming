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
int a[N], idxs[N], sz_idxs;
ll dp[2][N];
vi ans_idx;

ll solve(int idx, int prev){
    if(idx == sz_idxs) return 0;
    ll &ans = dp[prev][idx];
    if(~ans) return ans;
    if(prev){
        int x = idxs[idx], y = idxs[idx - 1];
        if(x - y > 2 || a[x] + a[y] < a[x - 1]) ans = a[x] + solve(idx + 1, 1);
        return ans = max(ans, solve(idx + 1, 0));
    }
    return ans = max(solve(idx + 1, 0), a[idxs[idx]] + solve(idx + 1, 1));
}

void trace(int idx,int prev){
    if(idx == sz_idxs) return;
    ll ans = dp[prev][idx];
    if(prev){
        int x = idxs[idx], y = idxs[idx - 1];
        if((x - y > 2 || a[x] + a[y] < a[x - 1]) && ans == a[x] + solve(idx + 1, 1)){
            ans_idx.push_back(idxs[idx]);
            trace(idx + 1, 1);
        }
        else trace(idx + 1, 0);
    }
    else {
        int x = idxs[idx];
        if(ans == a[x] + solve(idx + 1, 1)){
            ans_idx.push_back(idxs[idx]);
            trace(idx + 1, 1);
        }
        else trace(idx + 1, 0);
    }
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int T = nxt();
    while(T--){
        int n = nxt();
        a[0] = a[n + 1] = (int)1e9 + 123;
        ll sum = 0;
        rep(i,1,n+1) a[i] = nxt(), sum += a[i];
        sz_idxs = 0;
        rep(i,1,n+1){
            if(a[i - 1] > a[i] && a[i + 1] > a[i]) idxs[sz_idxs++] = i;
        }
        fill(dp[0], dp[0] + n + 2, -1);
        fill(dp[1], dp[1] + n + 2, -1);
        solve(0,0), trace(0,0);
        trav(x,ans_idx) a[x] = -a[x];
        ans_idx.clear();
        rep(i,1,n+1) cout << a[i] << " ";
        cout << '\n';
    }
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}