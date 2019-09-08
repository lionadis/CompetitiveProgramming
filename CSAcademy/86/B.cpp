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

int a[10], b[10], vis[10], n, s, c,  ans = 1e9;

void dfs(int curr_t, int curr_s, int curr_c){
    // cout << curr_t << " " << curr_s << " " << curr_c << '\n';
    int t = 1 + ((c - curr_c - 1) / curr_s);
    ans = min(ans, curr_t + max(0, t));
    rep(i,0,n){
        if(vis[i] == 0){
            vis[i] = 1;
            if(curr_c < a[i]){
                int t = 1 + ((a[i] - curr_c - 1) / curr_s);
                dfs(curr_t + t, curr_s + b[i], curr_c + t * curr_s - a[i]);

            } else {
                dfs(curr_t, curr_s + b[i], curr_c - a[i]);
            }
            vis[i] = 0;
        }
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    cin >> n >> c >> s;
    rep(i ,0, n) cin >> a[i] >> b[i];
    dfs(0, s, 0);
    cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}