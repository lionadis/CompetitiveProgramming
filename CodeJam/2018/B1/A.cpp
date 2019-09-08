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

const double eps = 0.0000001;

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int t = nxt();
    rep(T, 1, t + 1){
        int n = nxt(), l = nxt(), s = 0;
        rep(i,0,l) a[i] = nxt(), s += a[i];
        sort(a, a + l, [&](int x, int y){
            return 100.0 * x / n  - 100 * x / n > 100.0 * y / n - 100 * y / n;
        });
        rep(i,0,l){
            cout << 100.0 * a[i] / n << " ";
        }
        cout << '\n';
        int idx = 0;
        while(idx < l && s < n){
            if((100.0 * a[idx] / n - 100 * a[idx] / n) >= 0.5){
                idx++;
                continue;
            }
            a[idx]++;
            s++;
        }
        int cnt = 0;
        while(100.0 * cnt / n  - 100 * cnt / n < 0.5 && cnt < (n - s)) ++cnt;
        int ans  = 0;
        if(cnt) ans += (n - s) / cnt;
        ans *= round(100.0 * cnt / n);
        rep(i,0,l){
            ans += round(100.0 * a[i] / n);
        }
        cout << "Case # "<< T << ": "<< ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}