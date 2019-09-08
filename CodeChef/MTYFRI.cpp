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

const int N = 10123;
int a[2][N];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int t = nxt();
    while(t--){
        int n = nxt(), k = nxt();
        rep(i,0,n) a[i%2][i/2] = nxt();
        sort(a[0], a[0] + (n+1)/2);
        reverse(a[0], a[0] + (n+1)/2);
        sort(a[1], a[1] + n/2);
        rep(i,0,k){
            if(a[0][i] < a[1][i]) break;
            swap(a[0][i], a[1][i]);
        }
        int a0 = 0, a1 = 0;
        rep(i,0,(n+1)/2) a0 += a[0][i];
        rep(i,0,n/2) a1 += a[1][i];
        cout << (a0 < a1 ? "YES\n" : "NO\n");
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}