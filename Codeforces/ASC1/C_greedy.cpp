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
int p[maxn];
bool vis[maxn];
vi ans;

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
    rep(i,1,n) cin >> p[i], p[i]--;
    for(int u = n - 1; u > 0; --u){
        if(!vis[u] && !vis[p[u]]){
            vis[u] = vis[p[u]] = true;
            ans.push_back(u + 1);
        }
    }
    reverse(all(ans));
    cout << 1000LL * sz(ans) << '\n';
    trav(u, ans) cout << u << " ";
    cout << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}