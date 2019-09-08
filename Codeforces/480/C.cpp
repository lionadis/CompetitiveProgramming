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

const int maxn = 5123;
const int mod = 1e9 + 7;
int dp[maxn][maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n, k, a, b;
	cin >> n >> a >> b >> k;
	dp[0][a] = 1;
	rep(i,1,n + 1) dp[0][i] += dp[0][i - 1];
	rep(i,1,k + 1){
		rep(j,1,n + 1){
			if(j == b){
				dp[i][j] += dp[i][j - 1];
				continue;
			}
			if(j < b) dp[i][j] = (dp[i - 1][j + (b - j - 1) / 2] - (dp[i - 1][j] - dp[i - 1][j - 1] + mod) % mod) + mod, dp[i][j] %= mod;
			else dp[i][j] = (dp[i - 1][n] - dp[i - 1][b + (j - b) / 2] + mod) % mod - (dp[i - 1][j] - dp[i - 1][j - 1] + mod) % mod + mod, dp[i][j] %= mod;
			dp[i][j] += dp[i][j - 1];
			dp[i][j] %= mod;

		}
	}
	cout << dp[k][n] << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
