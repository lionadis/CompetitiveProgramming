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

const int maxn = 123;
int dp[maxn][maxn][5][5];

int solve(int i, int j, int x, int y){
    if(i == j){
        if(dp[i][j][x][y] == -1) dp[i][j][x][y] = -1e9;
        return dp[i][j][x][y];
    }
    int &res = dp[i][j][x][y];
    if(res != -1) return res;
    res = -1e9;
    rep(k, i, j){
        res = max(res, max(solve(i, k, x, y), solve(k + 1, j, x, y)));
        rep(t, 1, 5){
            res = max(res, solve(i, k, x, t) + solve(k + 1, j, t, y));
            res = max(res, solve(k + 1, j, x, t) + solve(i, k, t, y));
        }
    }
    return res;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    rep(i, 0, n){
        int c1, c2, v;
        cin >> c1 >> v >> c2;
        dp[i][i][c1][c2] = dp[i][i][c2][c1] = v;
    }
    int ans = 0;
    rep(x, 1, 5) rep(y, 1, 5) ans = max(ans, solve(0, n - 1, x, y));
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}