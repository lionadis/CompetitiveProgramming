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

string s;

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t;
    cin >> t;
    rep(T, 1, t + 1){
        int n;
        unordered_map<string, int> m;
        cin >> n;
        rep(i,0,n){
            cin >> s;
            trav(c, s) c = tolower(c);
            rep(j,0,sz(s)){
                m[s.substr(j, sz(s) - j)] ++;
            }
        }
        int ans = 0, cnt_ans = 0;
        trav(p, m){
            if(p.S >= 3){
                if(sz(p.F) > cnt_ans) cnt_ans = sz(p.F), ans = p.S;
                if(sz(p.F) == cnt_ans) ans = max(ans, p.S);
            }
        }
        cout << "Case " << T << ":\n" << cnt_ans << " " << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}