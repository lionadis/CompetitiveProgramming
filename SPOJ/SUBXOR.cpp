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

const int N = (int) 1e5 + 123;
int trie[20 * N][2], cnt[N], tot = 1;

void insert(int x){
    int now = 1;
    for(int i = 3; ~i; i--){
        int k = ((1 << i) & x) >> i;
        if(!trie[now][k]) trie[now][k] = ++tot;
        now = trie[now][k];
        cnt[now] ++;
    }
}

int solve(int now, int d, int k){
    cout << now << " ";
    if(d < 0) return cnt[now];
    if(now != 1 && cnt[now] == 0) return 0;
    if((1 << d) & k) return cnt[trie[now][0]] + solve(trie[now][1], d - 1, k & ((1 << d) - 1));
    else return solve(trie[now][0], d - 1, k & ((1 << d) - 1));
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int t = nxt();
    while(t--){
        int n = nxt(), k = nxt();
        ll ans = 0;
        rep(i,0,n){
            insert(nxt());
            ans += solve(1,3,k);
            cout << '\n';
        }
        cout << ans << '\n';
        cout << solve(1,3,k) << '\n';
    }   
}