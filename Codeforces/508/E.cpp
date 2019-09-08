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
const int maxm = 20;
int taken[maxm], cnt[maxm], cost[maxn], ans = 0, curr_ans = 0;
bool vis[maxn], ban[maxn];
pii lowest[maxm];
vi path;
vector<pii> g[5];

int compress(int u, int v){
    if(u > v) swap(u, v);
    return 4 * u + v;
}

bool checker(){
    rep(i, 1, sz(path)) cnt[compress(path[i], path[i - 1])] ++;
    rep(i, 0, maxm) if(cnt[i] > taken[i]) return false;
    return true;
}

void euler(int u){
    trav(e, g[u]){
        int v, idx;
        tie(v, idx) = e;
        if(vis[idx] || ban[idx]) {
            continue;
        }
        vis[idx] = true;
        curr_ans += cost[idx];
        taken[compress(u, v)] ++;
        euler(v);
    }
    path.push_back(u);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n;
    cin >> n;
    fill(lowest, lowest + maxm, (pii){1e9, -1});
    rep(i, 0, n){
        int u, c, v;
        cin >> u >> c >> v;
        --u, --v;
        lowest[compress(u, v)] = min(lowest[compress(u, v)], {c, i});
        cost[i] = c;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    rep(k, 0, 1 << 16){
        memset(ban, 0, sizeof ban);
        rep(i, 0, 16) if(k >> i & 1) if(lowest[i].S != -1) ban[lowest[i].S] = true;
        rep(i, 0, 4){
            memset(taken, 0, sizeof taken);
            memset(cnt, 0, sizeof cnt);
            memset(vis, 0, sizeof vis);
            path.clear();
            curr_ans = 0;
            euler(i);
            if(checker()) ans = max(curr_ans, ans);
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}