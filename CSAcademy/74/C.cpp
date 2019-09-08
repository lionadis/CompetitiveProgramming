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

const int MAXN = 210;
int a[MAXN][MAXN];

int sum(int x1, int y1, int x2, int y2){
    int res = a[x2][y2];
    if(x1) res -= a[x1-1][y2];
    if(y1) res -= a[x2][y1-1];
    if(x1 && y1) res += a[x1-1][y1-1];
    return res;
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n = nxt(), m = nxt(), k = nxt();
    rep(i,0,n) rep(j,0,m) a[i][j] = nxt();
    rep(i,0,n){
        rep(j,0,m){
            if(i) a[i][j] += a[i-1][j];
            if(j) a[i][j] += a[i][j-1];
            if(i && j) a[i][j] -= a[i-1][j-1];
        }
    }
    int ans = 0;
    rep(x1,0,n-k+1){
        rep(y1,0,m-k+1){
            rep(x2,0,n-k+1){
                rep(y2,0,m-k+1){
                    int tmp = sum(x1, y1, x1 + k - 1, y1 + k - 1) + sum(x2, y2, x2 + k - 1, y2 + k - 1);
                    if(x1 >= x2 && y1 >= y2) {if(x1 + k - 1 >= x2 && y1 + k - 1 >= y2) tmp -= sum(x2, y2, x1 + k - 1, y1 + k - 1);}
                    else if(x1 <= x2 && y1 <= y2) {if(x2 + k - 1 >= x1 && y2 + k - 1 >= y1) tmp -= sum(x1, y1, x2 + k - 1, y2 + k - 1);}
                    else if(x1 >= x2 && y1 <= y2) {if(x2 + k - 1 >= x1 && y1 + k - 2 >= y2) tmp -= sum(x1, y2, x2 + k - 1, y1 + k - 1);}
                    else if(x1 <= x2 && y1 >= y2) {if(x1 + k - 1 >= x2 && y2 + k - 2 >= y1) tmp -= sum(x2, y1, x1 + k - 1, y2 + k - 1);}
                    ans = max(ans, n * m - a[n-1][m-1] + tmp);
                }
            }
        }
    }
    cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}