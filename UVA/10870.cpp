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

int n, m, d, f0[17];

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
            if(p & 1) a = a * b;
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
    while(cin >> d >> n >> m, d){
        Matrix<ll, 15> M;
        rep(i,0,d) cin >> M.d[0][i];
        rep(i,0,d) cin >> f0[i];
        rep(i,1,d) M.d[i][i - 1] = 1;
        ll ans = 0;
        n--;
        M = M ^ n;
        rep(i,0,d) ans += M.d[d - 1][i] * f0[d - i - 1], ans %= m;
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}