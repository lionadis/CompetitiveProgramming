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

const int maxn = 231;
const int maxa = 2123;
int dp[maxn][maxn][maxa];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    freopen("important.in","r",stdin);
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int t;
    cin >> t;
    rep(T,1,t + 1){
        int n, m, q;
        cin >> n >> m >> q;
        memset(dp, 0, sizeof dp);
        rep(i,0,n){
            rep(j,0,m){
                int x;
                cin >> x;
                rep(k,0,maxa){
                    dp[i + 1][j + 1][k] = (x <= k) + dp[i][j + 1][k] + dp[i + 1][j][k] - dp[i][j][k];
                }
            }
        }
        cout << "Case " << T << ":\n";
        while(q--){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1 --, y1 --;
            int k = 1 + (x2 - x1) * (y2 - y1) / 2, l = 0, r = maxa;
            while(l < r){
                int mid = (l + r + 1) / 2;
                int cnt = dp[x2][y2][mid] - dp[x1][y2][mid] - dp[x2][y1][mid] + dp[x1][y1][mid];
                if(cnt < k) l = mid;
                else r = mid - 1;
            }
            cout << l + 1 << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}