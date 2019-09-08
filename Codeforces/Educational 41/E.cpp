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
#define debug(x) cerr << #x << " : " << x << "\n";
#define _ cin.sync_with_stdio(0); cin.tie(0);


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

struct FT{
    vl s;
    FT(int n):s(n){};
    void update(int pos, int val){
        for(;pos<sz(s);pos|=pos+1) s[pos] += val;
    }

    ll query(int pos){
        ll ans = 0;
        for(;pos>0;pos&=pos-1) ans += s[pos-1];
        return ans;
    }
};

const int N = 200123;
int a[N];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n = nxt();
    vi v(2 * n);
    rep(i,0,n) v[i] = nxt(), a[i] = v[i];
    rep(i,0,n) v[i + n] = i + 1;
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    ll ans = 0;
    FT ft(2 * n);
    rep(i,0,n){
        int idx = lower_bound(all(v), i + 1) - v.begin();
        ans += ft.query(2 * n) - ft.query(idx);
        cout << ft.query(2 * n) - ft.query(idx) << " ";
        idx = lower_bound(all(v), a[i]) - v.begin();
        ft.update(idx, 1);
    }
    cout << '\n';
    cout << ans << '\n';
    int tmp = 0;
    rep(i,0,n){
        rep(j,i+1,n) if(a[i] >= j+1 && a[j] >= i+1) tmp++, cout << i << " " << j << '\n';
    }
    cout << tmp << '\n';
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}