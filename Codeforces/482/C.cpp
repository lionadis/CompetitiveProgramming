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
#define dbg(x) cerr << #x << " : " << x << "\n";
#define _ cin.sync_with_stdio(0); cin.tie(0);


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

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int N = 300123;

vi g[N];
int n, x, y, cnt_path[N];
bool vis_y[N];

void dfs(int u, int p) {
	cnt_path[u] = 1;
    if(u == y) vis_y[u] = true;
	trav(v, g[u]) {
        if(v != p){
            dfs(v, u);
            if (vis_y[v]) vis_y[u] = true;
            cnt_path[u] += cnt_path[v];
        }
	}
}

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    n = nxt(), x = nxt() - 1, y = nxt() - 1;
	rep(i,0,n - 1){
		int u = nxt() - 1, v = nxt() - 1;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(x, -1);
	int cnt = 1;
	trav(v,g[x]) 
		if (!vis_y[v]) cnt += cnt_path[v];
	ll ans = 1LL * n * (n - 1);
    ans -= 1LL * cnt * cnt_path[y];
	cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}