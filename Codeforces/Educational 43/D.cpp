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

const int N = 1234;
const int M = 1000123;
int a[N];
pii p[M];

vector<vi> g;

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n = nxt(), sum = 0;
    int odd = 1e9, even = 1e9;
    rep(i,0,n){
        a[i] = nxt(), sum += a[i];
        if(a[i] % 2 == 0) even = min(even, a[i]);
        else odd = min(odd, a[i]);
    }
    g.resize(a[n - 1] + 123);
    int left = a[n - 1] + 1 - n;
    if(sum % 2 == 1) a[n++] = odd, left--;
    if(odd < even){
        rep(i,0,left/2 * 2) a[n++] = odd;
        if(left % 2 == 1) a[n++] = even;
    }
    else rep(i,0,left) a[n++] = even;
    sort(a, a + n);
    reverse(a, a + n);
    int ans = 0;
    rep(i,0,n){
        int j = i + 1;
        cout << a[i] << '\n';
        while(a[i]--) p[ans++] = {i + 1, j + 1}, a[j]--,j++;
    }
    cout << ans << '\n';
    rep(i,0,ans) cout << p[i].F << " " << p[i].S << '\n';
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}