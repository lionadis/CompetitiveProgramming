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

const int N = 300123;
pii a[N];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n = nxt(), x1 = nxt(), x2 = nxt();
    rep(i,0,n) a[i] = {nxt(), i + 1};
    sort(a, a + n);
    reverse(a, a + n);
    //x1 first
    int idx = 0;
    while(idx < n && x1 > 1LL * (idx + 1) * a[idx].F) idx++;
    if(idx < n - 1){
        int idx2 = idx + 1;
        while(idx2 < n && x2 > 1LL * (idx2 - idx) * a[idx2].F) idx2++;
        if(idx2 != n){
            cout << "Yes\n";
            cout << idx + 1 << ' ' << idx2 - idx << '\n';
            rep(i,0,idx2 + 1){
                cout << a[i].S << " ";
                if(i == idx) cout << '\n';
            }
            return  0;
        }
    }
    //x2 first
    idx = 0;
    while(idx < n && x2 > 1LL * (idx + 1) * a[idx].F) idx++;
    if(idx < n - 1){
        int idx2 = idx + 1;
        while(idx2 < n && x1 > 1LL * (idx2 - idx) * a[idx2].F) idx2++;
        if(idx2 != n){   
            cout << "Yes\n";
            cout << idx2 - idx<<  ' ' << idx + 1 << '\n';
            rep(i,idx+1,idx2 + 1) cout << a[i].S << " ";
            cout << '\n';
            rep(i,0,idx + 1) cout << a[i].S << " ";
            return 0;
        }
    }
    cout << "No\n";
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}