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
    for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc()); x*=f;
    return x;
}

const int N = 100100;

struct FT{
    vl s;
    FT(int n=N):s(n){};
    void update(int pos, ll val){
        for(;pos<sz(s);pos|=pos+1) s[pos]+=val;
    }
    ll query(int pos){
        ll sum = 0;
        for(;pos>0;pos&=pos-1) sum+=s[pos-1];
        return sum;
    }
};

struct RangeFT{
    FT ft1, ft2;
    void update(int l, int r, ll val){
        ft1.update(l, val);
        ft1.update(r+1,-val);
        ft2.update(l, val*(l-1));
        ft2.update(r+1, -val*r);
    }
    ll query(int pos){
        return ft1.query(pos+1)*pos - ft2.query(pos+1);
    }
    ll query(int l, int r){
        return query(r) - query(l-1);
    }
};

int main(){
#ifndef ONLINE_JUDGE
    f_out
#else
    _
#endif
    int t = 1;
    cout << t << '\n';
    srand(clock());
    while(t--){
        int n = 100000, m = 20000;
        cout << n << " " << m << '\n';
        rep(i,0,n) cout << rand() % 1000000 + 1 << " ";
        cout << '\n';
        while(m--){
            int op = rand()%3 + 1;
            cout << op << ' ';
            int l = rand()%n, s = rand()%(n-l);
            cout << l+1 << " " << l+s+1;
            if(op == 3) cout << " " << rand() % 1000000 + 1;
            cout << '\n';
        }
    }
}
