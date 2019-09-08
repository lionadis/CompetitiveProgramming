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
int a[N], gas[N], m, gas_tmp[N], n;
string s;

int solve(string b){
    int res = 0, mm = 0;
    rep(i,0,n) if(b[i] == '+') gas_tmp[mm++] = i;
    gas_tmp[mm] = (int) 1e9;
    int curr_mm = 0;
    rep(i,0,n){
        int x = abs(i - gas_tmp[curr_mm]), y = abs(i - gas_tmp[curr_mm + 1]);
        res = max(res, min(x, y));
        if(x > y) curr_mm++;
    }
    return res;
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
    //freopen("stress.out", "w", stdout);
#else
    _
#endif
    int t;
    cin >> t;
    while(t--){
        cin >> n >> s;
        m = 0;
        int ans = (int)1e9;
        rep(i,0,n) if(s[i] == '+') gas[m++] = i;
        rep(i,0,m){
            string a = s;
            a[gas[i]] = '.';
            rep(j,0,n){
                if(a[j] != '+'){
                    string b = a;
                    b[j] = '+';
                    ans = min(ans, solve(b));
                }
            }
        }
        cout << ans << '\n';

    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}