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
int a[N];

int sqr(ll k){
    int l = 0, r = N;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(1ll * mid * (mid + 1) / 2 <= k) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n = nxt();
    rep(i,0,n) a[i] = i + 1;
    ll k = nxt<ll>();
    int x = sqr(k);
    reverse(a + n - x - 1, a + n);
    k -= 1LL * x * (x + 1) / 2;
    int r = n - 1, l = n - x - 2;
    while(k--) swap(a[l], a[r--]);
    rep(i,0,n) cout << a[i] << " ";
    cout << '\n';


#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}