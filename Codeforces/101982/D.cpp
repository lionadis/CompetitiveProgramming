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

const int mod = 1e9 + 9, maxk = 1012, maxb = 130;
int dp[maxb][maxb][maxk], k, b;

int solve(int bits, int ones, int left){
	if(bits == 0) return (left == 0 ? ones : 0);
	int &res = dp[bits][ones][left];
	if(~res) return res;
	return res = (solve(bits - 1, ones, (left * 2) % k) + solve(bits - 1, ones + 1, (left * 2 + 1) % k)) % mod;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	memset(dp, -1, sizeof dp);
	cin >> k >> b;
	cout << solve(b, 0, 0) << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
