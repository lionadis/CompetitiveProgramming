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

const int maxn = 100123;
int cnt[maxn];
vector<int> G[maxn];

void dfs(int u, int p, int h){
	cnt[h] ^= 1;
	trav(v, G[u]){
		if(v == p) continue;
		dfs(v, u, h + 1);
	}
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n;
	cin >> n;
	rep(i,1,n){
		int x;
		cin >> x;
		x--;
		G[i].push_back(x);
		G[x].push_back(i);
	}
	dfs(0, 0, 0);
	int ans = 0;
	rep(i,0,maxn) ans += cnt[i];
	cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
