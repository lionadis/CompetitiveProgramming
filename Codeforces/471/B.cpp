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
#define tl cerr <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n"
#define Func {ans += solve(i); ++i;}


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

int cnt[10];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    string s;
    cin >> s;
    string ss = s;
    sort(all(ss));
    ss.erase(unique(all(ss)), ss.end());
    if(sz(s) < 4){
        cout << "No\n";
        return 0;
    }
    if(sz(ss) == 2){
        rep(i,0,sz(s)){
            if(s[i] == ss[0]) cnt[0] ++ ;
            else cnt[1] ++ ;
        }
        if(cnt[0] == 1 || cnt[1] == 1) cout <<  "No\n";
        else cout << "Yes\n";
    }
    else if(sz(ss) == 3 || sz(ss) == 4){
        cout << "Yes\n";
    } else cout << "No\n";
}