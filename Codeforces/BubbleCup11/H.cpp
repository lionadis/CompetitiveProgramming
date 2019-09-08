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

const int alpha = 26;
unordered_map<int, int> cnt;

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n;
    cin >> n;
    ll ans = 0;
    rep(i,0,n){
        string s;
        cin >> s;
        int mask = 0;
        trav(c, s) mask ^= (1 << (c - 'a'));
        rep(k,0,26) ans += cnt[mask ^ (1 << k)];
        ans += cnt[mask]++;
    }
    cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}