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
const int N = 4;
int n, T;

struct M{
    vector<vi> val;
    M(){
        val.resize(20);
        rep(i,0,20) val[i].resize(20);
    }

    M operator*(const M &b){
        M ans;
        rep(i, 0, 1 << N) rep(j, 0, 1 << N)
        rep(k, 0, 1 << N) ans.val[i][j] += val[i][k] * b.val[k][j];
        return ans;
    }
} a, base, ans;

void solve(int idx, int curr, int mask){
    if(idx >= N){
        a.val[mask][curr]++;
        return;
    }
    int k = mask & 1 << idx;
    if(k) solve(idx + 1, curr, mask);
    else{
        solve(idx + 1, curr | 1 << idx, mask);
        if( idx + 2 <= N && (mask & 1 << (idx + 1)) == 0) solve(idx + 2, curr, mask);
    }
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    T = nxt();
    rep(i,0,1 << N) solve(0, 0, i);
    rep(t, 1, T + 1){
        n = nxt();
        base = a;
        rep(i, 0 ,1 << N){
            rep(j, 0, 1 << N) ans.val[i][j] = ( i == j ? 1 : 0);
        }
        while(n){
            if(n & 1) ans = ans * base;
            base = base * base;
            n /= 2;
        }
        cout << t << " " << ans.val[0][0] << '\n';
    }
}