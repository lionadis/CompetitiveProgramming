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

const int N = 110;
int ans[N][N];
string s[N];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n, k;
    cin >> n >> k;
    rep(i,0,n) cin >> s[i];
    rep(i,0,n){
        rep(j,0,n){
            int ii = i, jj = j;
            int tmp = k;
            while(ii < n && s[ii][j] != '#' && tmp) ii++, tmp--;
            if(tmp == 0) rep(ii,0,k) ans[ii + i][j]++;
            tmp = k;
            while(jj < n && s[i][jj] != '#' && tmp) jj++, tmp --;
            if(tmp == 0) rep(jj,0,k) ans[i][jj + j]++;
        }
    }
    int res = 0, ans_i = 0, ans_j = 0;
    rep(i,0,n)
        rep(j,0,n){
            if(res < ans[i][j]) res = ans[i][j], ans_i = i, ans_j = j;
        }
    cout << ans_i + 1 << " " << ans_j + 1 << '\n';
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}