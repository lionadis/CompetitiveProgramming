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
int a[N], b[N];
unordered_map<int, int> idxs;

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int t = nxt();
    while(t--){
        int n = nxt(), q = nxt();
        idxs.clear();
        rep(i,0,n) a[i] = nxt(), idxs[a[i]] = i, b[i] = a[i];
        sort(b, b + n);
        while(q--){
            int l = 0, r = n - 1, x = nxt(), ans_s = 0, ans_g = 0;
            int smaller = lower_bound(b, b + n, x) - b;
            int bigger = n - 1 - smaller;
            while(l <= r){
                int mid = (l + r) / 2;
                if(mid == idxs[x]) break;
                else if(mid < idxs[x]){
                    if(a[mid] > x) ans_s ++;
                    smaller--;
                    l = mid  + 1;
                }
                else {
                    if(a[mid] < x) ans_g ++;
                    bigger--;
                    r = mid - 1;
                }
            }
            int ans = max(ans_g, ans_s);
            if(smaller < 0 || bigger < 0) ans = -1;
            cout << ans << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}