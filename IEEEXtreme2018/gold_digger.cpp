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

string s;
const int maxn = 21;
int dp[2][maxn][maxn][128], n;

vector<int> G[maxn];

int solve(int p, int u, int v, int mask){
	int &res = dp[p][u][v][mask];
	if(~res) return res;
	if(u == 

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	cin >> n;
	getline(cin, s);
	memset(dp, -1, sizeof dp);
	rep(i,0,n){
		getline(cin, s);
		stringstream ss(s);
		int u;
		while(ss >> u) G[i].push_back(u);
	}
	cout << solve(0,0,0,0) << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
