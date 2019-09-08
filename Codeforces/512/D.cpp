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

const int maxn = 300123;
const int lgn = 75;
int f[maxn], s[maxn], c[maxn][2], b[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n;
    cin >> n;
    rep(i,1,n+1){
        int x;
        cin >> x;
        f[i] = __builtin_popcount(x);
    }    
    rep(i,1,n+1){
        s[i] = s[i - 1] + f[i];
		c[i][1] = c[i - 1][1];
		c[i][0] = c[i - 1][0];
        c[i][s[i] % 2]++;
    }
    int last = n + 1;
    for(int i = n; i >= 0; --i){
        b[i] = last;
        if(f[i]) last = i;
    }
    ll ans = 0;
    rep(i,1,n+1){
        int x = s[i - 1] % 2;
        int last = i, mx = f[i], sum = f[i];
        rep(j,1,lgn){
            int id = b[last];
            if(sum / 2 >= mx) ans += c[id - 1][x] - c[last - 1][x];
            mx = max(mx, f[id]), sum += f[id], last = id;
            if(last > n) break;
        }
        ans += c[n][x] - c[last - 1][x];
    }
    cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}