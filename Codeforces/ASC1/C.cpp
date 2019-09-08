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

const int maxn = 500123;
int dp[maxn][2];
vector<int> G[maxn], ans;

int dfs(int u, int p, int took){
    int &res = dp[u][took];
    if(res != -1) return res;
    res = 0;
    trav(v, G[u]){
        if(v != p) res += dfs(v, u, 0);
    }
    int all_zero = res;
    if(!took){
        trav(v, G[u]){
            if(v != p) res = max(res, all_zero + 1 + dfs(v, u, 1) - dfs(v, u, 0));
        }
    }
    return res;
}

void trace(int u, int p, int took){
    int res = dp[u][took];
    int cnt = 0;
    trav(v, G[u]){
        if(v != p){
            cnt += dfs(v, u, 0);
        }
    }
    if(cnt == res){
        trav(v, G[u]){
            if(v != p){
                trace(v, u, 0);
            }
        }
        return;
    }
    if(!took){
        trav(v, G[u]){
            if(v != p){
                if(res == cnt + 1 + dfs(v, u, 1) - dfs(v, u, 0)){
                    ans.push_back(v);
                    trace(v, u, 1);
                    trav(v1, G[u]){
                        if(v1 != p && v != v1){
                            trace(v1, u, 0);
                        }
                    }
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
    freopen("grant.in", "r", stdin);
    freopen("grant.out", "w", stdout);
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n;
    cin >> n;
    rep(i,0,n - 1){
        int x;
        cin >> x;
        x--;
        G[i + 1].push_back(x);
        G[x].push_back(i + 1);
    }
    memset(dp, -1, sizeof dp);
    cout << 1LL * dfs(0, 0, 0) * 1000 << '\n';
    trace(0, 0, 0);
    sort(all(ans));
    trav(x, ans) cout << x + 1 << ' ';
    cout << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}