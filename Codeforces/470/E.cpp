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

const int N = 100123;
int a[2][N], b[2][N];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    string s, t;
    cin >> s >> t;
    rep(i,0,sz(s)){
        if(s[i] != 'A') a[0][i] = 1, a[1][i] = i;
    }
    rep(i,1,sz(s)) a[0][i] += a[0][i - 1], a[1][i] = max(a[1][i], a[1][i - 1]);
    rep(i,0,sz(t)){
        if(t[i] != 'A') b[0][i] = 1, b[1][i] = i;
    }
    rep(i,1,sz(t)) b[0][i] += b[0][i - 1], b[1][i] = max(b[1][i], b[1][i - 1]);
    int q;
    cin >> q;
    while(q--){
        int ls, rs, lt, rt;
        cin >> ls >> rs >> lt >> rt;
        ls--, rs--, lt--, rt--;
        int cntBs = a[0][rs], cntBt = b[0][rt];
        if(ls) cntBs -= a[0][ls - 1];
        if(lt) cntBt -= b[0][lt - 1];
        int trailAs = rs - max(a[1][rs], ls), trailAt = rt - max(b[1][rt], lt);
        if(a[1][rs] <= ls && s[ls] == 'A') trailAs++;
        if(b[1][rt] <= lt && t[lt] == 'A') trailAt++;
        if(!cntBs && cntBt && cntBt % 2 == 0 && trailAt < trailAs) cout << '1';
        else if(cntBs <= cntBt && cntBs % 2 == cntBt % 2 && trailAs >= trailAt && trailAs % 3 == trailAt % 3) cout << '1';
        else cout << '0';
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}