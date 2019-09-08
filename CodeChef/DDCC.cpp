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

const int maxn = 200123;
const int maxc = 1000123;
int a[maxn], cnt[maxc], SQRT;
pair<pii, int> Q[maxn];
ll ans[maxn], curr_ans = 0;

bool cmp(pair<pii, int> &a, pair<pii, int> &b){
    if(a.F.F / SQRT != b.F.F / SQRT) return a.F.F / SQRT < b.F.F / SQRT;
    return a.F.S / SQRT < b.F.S / SQRT;
}

void add(int x){
    curr_ans -= 1LL * cnt[x] * cnt[x] * x;
    cnt[x]++;
    curr_ans += 1LL * cnt[x] * cnt[x] * x;
}

void remove(int x){
    curr_ans -= 1LL * cnt[x] * cnt[x] * x;
    cnt[x]--;
    curr_ans += 1LL * cnt[x] * cnt[x] * x;
}

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int n = nxt(), d = nxt();
    rep(i,0,n) a[i] = nxt();
    SQRT = sqrt(d + .0) + 1;
    rep(i,0,d){
        Q[i] = {{nxt() - 1, nxt() - 1}, i};
    }
    sort(Q, Q + d, cmp);
    int currL = 0, currR = -1;
    rep(i,0,d){
        int L = Q[i].F.F, R = Q[i].F.S, idx = Q[i].S;
        while(currL > L) add(a[--currL]);
        while(currL < L) remove(a[currL++]);
        while(currR < R) add(a[++currR]);
        while(currR > R) remove(a[currR--]);
        ans[idx] = curr_ans;
    }
    rep(i,0,d) cout << ans[i] << "\n";
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}