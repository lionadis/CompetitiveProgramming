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

const int MAXN = 5000132;

int ft[MAXN];


vi v;
int uf[MAXN], mark[MAXN], n, m, lim; 
bool vis[MAXN], cnt[MAXN], already_done[MAXN];

inline void update(int d) {
	for(;d<=n;d+=d&-d)
		ft[d]++;
}
inline int query(int d) {
	int res=0;
	for(;d;d-=d&-d)
		res+=ft[d];
	return res;
}

void init(){
    rep(i,0,lim + 1) uf[i] = i;
}
int find(int a){
	if (a == uf[a]) return a;
	return uf[a] = find(uf[a]);
}

void solve(int u, int v){
	if (vis[u]){
		if (already_done[u]){
			int a = find(v), b = find(mark[u]);
			uf[b] = a;
		}
		return;
	}
	vis[u] = true;
	if (cnt[u]){
		already_done[u] = true, mark[u] = u;
		int a = find(v), b = find(u);
		uf[b] = a; 
	}
	rep(k,0,n)
		if (u >> k & 1){
			int dst = u - (1 << k);
			if (vis[dst]){
				if (already_done[dst]){
					already_done[u] = true;
					if (mark[u] == -1) mark[u] = mark[dst];
					int a = find(v), b = find(mark[dst]);
					uf[b] = a;
				}
			}
            else {
                solve(dst, v);
                if (already_done[dst] && mark[u] == -1){
                    already_done[u] = true;
                    mark[u] = mark[dst];
                }
            }
		} 
}
int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    memset(mark, -1, sizeof mark);
	n = nxt();
	m = nxt(); 
	lim = 1 << n;
    init();
	rep(i,0,m){
		int x = nxt();
		cnt[x] = true;
		v.push_back(x);
	}
	trav(x, v){
		int markall = lim - 1 - x;
		solve(markall, x);
	}
	int ans = 0;
	trav(t, v) if (find(t) == t) ans++;
    cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}