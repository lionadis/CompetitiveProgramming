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

const int maxn = 2123;
int n, m;
int dp[maxn][maxn];
pair<int, string> a[maxn], b[maxn];
vector<vector<string> > rides;

int solve(int x, int y){
    if(x == n) return (y == m ? 0 : 1e9);
    int &res = dp[x][y];
    if(~res) return res;
    res = 1e9;
    rep(i,1,5){
        rep(j,0,5 - i){
            if(x + i <= n && y + j <= m){
                res = min(res, solve(x + i, y + j) + max(a[x + i - 1].F, (y + j - 1 >= 0 ? b[y + j - 1].F : -1)));
            }
        }
    }
    return res;
}

void trace(int x, int y){
    if(x == n && y == m) return;
    // cout << x << " " << y << '\n';
    int res = solve(x, y);
    rep(i,1,5){
        rep(j,0,5 - i){
            if(x + i <= n && y + j <= m){
                if(res == solve(x + i, y + j) + max(a[x + i - 1].F, (y + j - 1 >= 0 ? b[y + j - 1].F : -1))){
                    vector<string> tmp;
                    rep(ii, 0, i) tmp.push_back(a[x + ii].S);
                    rep(jj, 0, j) tmp.push_back(b[y + jj].S);
                    rides.push_back(tmp);
                    trace(x + i, y + j);
                    return;
                }
            }
        }
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    freopen("taxi.in","r",stdin);
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    cin >> n;
    rep(i,0,n) cin >> a[i].S >> a[i].F;
    sort(a, a + n);
    cin >> m;
    rep(i,0,m) cin >> b[i].S >> b[i].F;
    sort(b, b + m);
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << '\n';
    trace(0, 0);
    cout << sz(rides) << '\n';
    rep(i,0,sz(rides)){
        cout << "Taxi " << i + 1 << ": ";  
        rep(j,0,sz(rides[i])){
            if(j == sz(rides[i]) - 1) cout << rides[i][j] << ".\n";
            else if(j == sz(rides[i]) - 2) cout << rides[i][j] << " and ";
            else cout << rides[i][j] << ", ";
        }
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}