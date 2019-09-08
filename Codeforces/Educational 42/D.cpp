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

const int N = 200150;
ll a[N];
map<ll, set<ll>> m;
vector<ll> ans;
int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    int n = nxt();
    rep(i,0,n) a[i] = nxt(), m[a[i]].insert(i);

    auto it = m.begin();
    while(it != m.end()){
        if(it->S.size() >= 2){

			ll x = *it->S.begin(); it->S.erase(it->S.begin());
			ll y = *it->S.begin(); it->S.erase(it->S.begin());
			a[x] = 0;
			a[y] = a[y] * 2;
			m[a[y]].insert(y);
		}
		else it++;
    }
    rep(i, 0, n) if(a[i]) ans.push_back(a[i]);
    cout << sz(ans) << '\n';
    rep(i,0,sz(ans)) cout << ans[i] << " ";

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}