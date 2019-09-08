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

const int N=123;
int a[4][N][N];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n;
    cin >> n;
    rep(k,0,4)
        rep(i,0,n)
            rep(j,0,n){
                char c;
                cin >> c;
                a[k][i][j] = (int)(c - '0');
            }
    vi perm = {0, 1, 2, 3};
    int ans = 1e9;
    do{
        int curr = 0;
        rep(k,0,4){
            rep(i,0,n){
                rep(j,0,n){
                    if(k % 2 == 0){
                        if((i + j) % 2 == 0 && a[perm[k]][i][j] == 0) curr++;
                        if((i + j) % 2 == 1 && a[perm[k]][i][j] == 1) curr++;
                    }
                    if(k % 2 == 1){
                        if((i + j) % 2 == 0 && a[perm[k]][i][j] == 1) curr++;
                        if((i + j) % 2 == 1 && a[perm[k]][i][j] == 0) curr++;
                    }
                }
            }
        }
        ans = min(curr, ans);
    }while(next_permutation(all(perm)));
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}