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
#define tl cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n"
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

const int MAXN = (int)1e5 + 123;
int trie[10 * MAXN][27], cnt[10 * MAXN], tot = 1;

void insert(string &s){
    int now = 1;
    trav(c, s){
        int idx = c - 'a';
        if(!trie[now][idx]) trie[now][idx] = ++tot;
        now = trie[now][idx];
        cnt[now] ++;
    }
}

int query(string &s){
    int now = 1;
    trav(c, s){
        int idx = c - 'a';
        now = trie[now][idx];
    }
    return cnt[now];
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n, q;
    cin >> n >> q;
    rep(i,0,n){
        string s;
        cin >> s;
        insert(s);
    }
    rep(i,0,q){
        string s;
        cin >> s;
        cout << query(s) << '\n';
    }
}