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

const int N = (int) 1e6 + 123;
string a[N];
int trie[N][27], cnt[N], tot = 1;

void insert(string s){
    int now = 1;
    trav(c, s){
        int k = c - 'a';
        if(!trie[now][k]) trie[now][k] = ++tot;
        now = trie[now][k];
        cnt[now]++;
    }
}

ll query(string s){
    ll res = 0, now = 1;
    rep(i,0,sz(s)){
        int k = s[i] - 'a';
        now = trie[now][k];
        res += (cnt[now] - 1) * (i + 1);
        if(i) res -= (cnt[now] - 1) * i;
    }
    return res;
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    ll n;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        insert(a[i]);
    }
    ll ans = 0;
    rep(i,0,n){
        ans += query(a[i]);
    }

    cout << fixed << setprecision(10) << 1.0  * ans / (n * (n  - 1));

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}