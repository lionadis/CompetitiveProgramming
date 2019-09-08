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
    int t = nxt();
    rep(T,0,t){
        vi a(10), aa;
        rep(i,0,10) a[i] = nxt();
        sort(all(a));
        aa = a;
        vi ans;
        do{
            vi v(5);
            v[0] = (a[0] - a[1] + a[2]) / 2;
            v[1] = (a[0] - a[2] + a[1]) / 2;
            v[2] = (a[2] - a[0] + a[1]) / 2;
            v[3] = (a[9] - a[4] + a[3]) / 2;
            v[4] = (a[9] - a[3] + a[4]) / 2;
            vi b;
            rep(i,0,5){
                rep(j,i + 1,5){
                    b.push_back(v[i] + v[j]);
                }
            }
            sort(all(b));
            // trav(x, b) cout << x << " ";
            // cout << '\n';
            if(aa == b){
                sort(all(v));
                ans = v;
                break;
            }
        }while(next_permutation(a.begin() + 1, a.begin() + 9));
        cout << "Case " << T + 1 << ": ";
        rep(i,0,sz(ans)) cout << ans[i] << (i == 4 ? "":" ");
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}