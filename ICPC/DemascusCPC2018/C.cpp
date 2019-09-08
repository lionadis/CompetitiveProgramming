#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define F first
#define S second
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

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        int n  = sz(b), rev = 0, ans = 0;
        rep(i,0,n / 2 + 1){
            if(rev){
                if(a[n - i - 1] == b[i]) continue;
                if(a[i] == b[i] && a[n - i - 1] == b[n - i - 1]) ans++, rev = 0;
                else {
                    ans = -1;
                    break;
                }
            }
            else {
                if(a[i] == b[i]) continue;
                if(a[n - i - 1] == b[i] && a[i] == b[n - i - 1]) ans++, rev = 1;
                else {
                    ans = -1;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}