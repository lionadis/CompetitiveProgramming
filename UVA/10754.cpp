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

int k, n, m, f[25];

template<class T, int N> struct Matrix{
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator *(M &a) const{
        M b;
        rep(i,0,N) rep(j,0,N) rep(k,0,N) b.d[i][j] += d[i][k] * a.d[k][j], b.d[i][j] %= m;
        return b;
    }
    M operator ^(int p) const{
        M a, b(*this);
        rep(i,0,N) a.d[i][i] = 1;
        while(p){
            if(p&1) a = a * b;
            b = b * b;
            p >>= 1;
        }
        return a;
    }
};

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int t;
    cin >> t;
    while(t--){
        cin >> k >> m >> n;
        Matrix<ll, 21> M;
        rep(i,0,k) cin >>  M.d[0][i], M.d[0][i] %= m, M.d[0][i] += m, M.d[0][i] %= m;
        M.d[0][k] = M.d[k][k] = 1;
        cin >> f[k];
        f[k] %= m, f[k] += m, f[k] %= m;
        rep(i,0,k) cin >> f[k - i - 1], f[k - i - 1] %= m, f[k - i - 1] += m, f[k - i - 1] %= m;
        rep(i,1,k) M.d[i][i - 1] = 1;
        M = M ^ n;
        ll ans = 0;
        // rep(i,0,k + 1){
        //     rep(j,0,k + 1) cout << M.d[i][j] << " ";
        //     cout << '\n';
        // }
        // rep(i,0,k + 1) cout << f[i] << ' ';
        // cout << '\n';
        rep(i,0,k + 1) ans += M.d[max(0, k - 1)][i] * f[i], ans %= m;
        cout << ans << "\n";
        if(t) cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}