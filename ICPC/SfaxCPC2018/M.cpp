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

const int maxn = 100123;
int a[maxn];
bool first[maxn];
unordered_map<int, bool> vis;

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    freopen("smallest.in", "r", stdin);
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int t = nxt();
    while(t--){
        int n = nxt();
        rep(i,0,n) a[i] = nxt();
        //LEFT
        int l = 0, r = n - 1;
        while(l != r && a[l] == a[l + 1]) ++l;
        rep(i,l,n){
            if(!vis.count(a[i])) first[i] = true, vis[a[i]] = 1;
        }
        while(r != l && !first[r]) r--;
        int ans1 = r - l + 1;
        vis.clear();
        fill(first, first + n, false);
        //RIGHT
        l = 0, r = n - 1;
        while(r != l && a[r] == a[r - 1]) r--;
        for(int i=r;i>=0;--i){
            if(!vis.count(a[i])) first[i] = true, vis[a[i]] = 1;
        }
        while(r != l && !first[l]) l++;
        int ans2 = r - l + 1;
        vis.clear();
        fill(first, first + n, false);
        //ANS
        cout << min(ans1, ans2) << '\n';

    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}