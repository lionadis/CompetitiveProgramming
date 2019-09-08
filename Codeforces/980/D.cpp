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

const int N = 5123;
const int MAXN2 = 200000123;
const int INF = 100000000;

int a[N], b[N], d[2 * N];
bool vis[MAXN2];

int main(){
#ifdef LOCAL_DEFINE
    f_in
#else
    _
#endif
    rep(i,1,2 * N) d[i] = i * i;
	int n = nxt();
	rep(i,1,n+1){
		a[i] = nxt();
		for (int j = 2; d[j] <= a[i]; j++)
			while (!(a[i] % d[j]))
				a[i] /= d[j];
		a[i] += INF;
	}
	rep(i,1,n+1){
		int x = 0;
		rep(j,i,n+1){
			if (a[j] != INF){
				if (!vis[a[j]]) x++;
				vis[a[j]] = true;
			}
			b[x]++;
		}
		rep(j,i,n+1) vis[a[j]] = false;
	}
	b[1] += b[0];
	rep(i,1,n+1) cout << b[i] << " ";


#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}