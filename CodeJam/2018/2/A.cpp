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

const int N = 123;
int a[N], b[N];
string s[N];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int t = nxt();
    rep(T,1,t + 1){
        cout << "Case #" << T << ":" << " ";
        int n = nxt();
        rep(i,0,n) a[i] = nxt(), b[i] = 1;
        if(a[0] == 0 || a[n - 1] == 0){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        rep(i,0,n){
            rep(j,0,n) s[i][j] = '.';
        }
        int h = *max_element(a, a + n);
        int cnt_l = 0;
        rep(i,0,n-1){
            while(b[i] > a[i]){
                if(cnt_l){
                    cnt_l--;
                    break;
                }
                rep(j,0,b[i] - a[i]){
                    s[j][i] = '\\';
                }
                b[i + 1] ++;
                b[i] --;
            }
            if(b[i] < a[i]) cnt_l += a[i] - b[i];
        }
        for(int i=n-1;i>=1;i--){
            while(b[i] > a[i]){
                rep(j,0,b[i] - a[i]){
                    s[j][i] = '/';
                }
                b[i - 1] ++;
                b[i] --;
            }
        }
        cout << h << '\n';
        rep(i,0,h){
            rep(j,0,n) cout << s[i][j];
            cout << '\n';
        }
    }


#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}