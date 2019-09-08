#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define F first
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    ll n, m, k; 
    cin >> n >> m >> k;
    ll s = (2 * n * m) / k;
    if (k == 1) return cout << "NO" << '\n', 0;
    if (s * k != 2 * n * m) return cout << "NO" << '\n', 0;
    cout << "YES" << '\n';
    if (k % 2) {
        ll g = __gcd(n, k); 
        n /= g;
        if (g > 1) n *= 2;
        k /= g;
        m /= k;
        if (g == 1) m *= 2;
    } else {
        k /= 2;
        ll g = __gcd(n, k);
        n /= g;
        k /= g;
        m /= k;
    }
    cout << 0 << " " << 0 << '\n';
    cout << 0 << " " << m << '\n';
    cout << n << " " << 0 << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}