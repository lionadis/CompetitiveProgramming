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

const ll inf = (ll)1e18;
const int N = 200123;
ll a[N], s[N];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n = nxt(), q = nxt();
    rep(i,1,n+1) a[i] = nxt();
    rep(i,1,n+1) s[i] = a[i] + s[i - 1];
    s[n+1] = inf;
    int idx = 1;
    ll last = a[idx];

    while(q--){

        ll x = nxt<ll>();
        int l = idx, r = n + 1, mid = n + 1;

        while (l <= r) {
            int curr_mid = (l + r) >> 1;
            if (s[curr_mid] - s[idx] + last > x) {
                mid = min(mid, curr_mid);
                r = curr_mid - 1;
            } else {
                l = curr_mid + 1;
            }
        }

        if (mid == n + 1) {
            cout << n << "\n";
            idx = 1;
            last = a[idx];
        } else {
            ll curr_cnt = s[mid] - s[idx] + last - x;
            last = curr_cnt;
            idx = mid;
            cout << n - mid + 1 << "\n";
        }
    }
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}