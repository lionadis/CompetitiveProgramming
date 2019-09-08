#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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

const int maxn = 1234;
ll l[maxn], r[maxn], a[maxn];



int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n = nxt();
    rep(i,1,n + 1) l[i] = nxt();
    rep(i,1,n + 1) r[i] = nxt();
    int p = 0;
    rep(i,1,n + 1) {
        if (l[i] == 0 && r[i] == 0) a[i] = n,p++;
        else a[i] = -1;
    }
    
    for (int i = n - 1; i >= 1; i--) {
        int occ = 0, cp = 0;
        for (int k = 1; k <= n; k++) {
            if (a[k] > 0) { occ++; continue; }
            if (l[k] == occ && r[k] == p - occ)  a[k] = i, cp++;
        }
        p += cp;
    }
    rep(i,1,n + 1) if (a[i] < 0)  return cout << "NO\n",0;
    cout << "YES" << endl;
    rep(i,1,n + 1) {
        cout << a[i] << " ";
    }
    cout << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}