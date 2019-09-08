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

const int maxn = 4123;
const int maxm = 812;
const int inf = 1e9 + 7;
int a[maxn][maxn], sum[maxn][maxn], dp[maxm][maxn];

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

int query(int l, int r){
	return sum[r + 1][r + 1] - sum[r + 1][l] - sum[l][r + 1] + sum[l][l];
}

void solve(int k, int l, int r, int optl, int optr){
	if(l > r) return;
	int mid = (l + r) / 2;
	pii best = {inf, -1};
	rep(i,optl, min(mid, optr) + 1) best = min(best, {dp[k - 1][i] + query(i + 1, mid), i});
	dp[k][mid] = best.F;
	solve(k, l, mid - 1, optl, best.S);
	solve(k, mid + 1, r, best.S, optr);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n = nxt(), m = nxt();
	rep(i, 1, n + 1) rep(j,1,n + 1) a[i][j] = nxt();
	rep(r, 1, n + 1) rep(c, 0, n + 1) sum[r + 1][c + 1] = a[r][c] + sum[r + 1][c] + sum[r][c + 1] - sum[r][c];
	rep(i, 1, n + 1) dp[1][i] = query(1, i);
	rep(i, 2, m + 1) solve(i, 1, n, 0, n);
	cout << dp[m][n] / 2<< '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
