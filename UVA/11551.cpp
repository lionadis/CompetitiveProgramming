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

const int mod = 1000;
int f[50];

template<class T, int N> struct Matrix{
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(M &a){
        M b;
        rep(i,0,N) rep(j,0,N) rep(k,0,N) b.d[i][j] += d[i][k] * a.d[k][j], b.d[i][j] %= mod;
        return b;
    }
    M operator^(int p){
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
        int n, r;
        cin >> n >> r;
        rep(i,0,n) cin >> f[i];
        Matrix<ll, 50> M;
        rep(i,0,n){
            int x;
            cin >> x;
            rep(j,0,x){
                int idx;
                cin >> idx;
                M.d[i][idx] = 1;
            }
        }
        M = M ^ r;
        rep(i,0,n){
            ll x = 0;
            rep(j,0,n) x += M.d[i][j] * f[j], x %= mod;
            cout << x << " ";
        }
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}