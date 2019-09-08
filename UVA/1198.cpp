/*
    Precompute ASAP, and mark each nodes the appear in any pair in the shortest path between each pair in the given subset
    if all the nodes are marked , the answer is yes, otherwise no
*/

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

const int maxn = 123;
int a[maxn][maxn];

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int n;
    cin >> n;
    cin.ignore();
    rep(i,0,n) rep(j,0,n) a[i][j] = 1235;
    rep(i,0,n){
        string s;
        getline(cin, s);
        stringstream ss(s);
        int u;
        while(ss >> u) a[i][u - 1] = 1;
    }
    rep(i,0,n) a[i][i] = 0;
    rep(k,0,n)
        rep(i,0,n)
            rep(j,0,n) a[i][j] = min(a[i][k] + a[k][j], a[i][j]);
    int q;
    cin >> q;
    cin.ignore();
    while(q--){
        string s;
        getline(cin, s);
        stringstream ss(s);
        vi b;
        int x;
        while(ss >> x) b.push_back(x - 1);
        ll vis = 0;
        trav(u, b)
            trav(v, b)
                rep(w,0,n)
                    if(a[u][w] + a[w][v] == a[u][v]) vis |= 1LL << w;
        if((1LL << n) - 1 == vis) cout << "yes\n";
        else cout << "no\n";
    }
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}