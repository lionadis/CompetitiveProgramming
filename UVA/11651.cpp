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

const int B = 6;
unsigned dp[B][B * B], f[B * B * B];

template<class T, int N> struct Matrix{
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator *(M &a) const{
        M b;
        rep(i,0,N) rep(k,0,N) if(d[i][k])  rep(j,0,N) b.d[i][j] += d[i][k] * a.d[k][j];
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
    rep(T,1,t + 1){
        int n, b;
        cin >> b >> n;
        memset(dp, 0, sizeof dp);
        memset(f, 0, sizeof f);
        rep(i,0,b) dp[i][0] = 1;
        b--;
        rep(i, 1, b * b){
            rep(j, 0, b + 1){
                rep(k,0,b + 1){
                    if(i < (j - k) * (j - k) || k == j) continue;
                    dp[j][i] += dp[k][i - (j - k) * (j - k)];
                }
            }
        }
        Matrix<unsigned, 150> M;
        rep(i,0,b + 1){
            rep(j,0,b * b) f[i * b * b + (b * b - j - 1)] = dp[i][j];
        }
        // rep(i,0,b * b * (b + 1)) cout << f[i] << " ";
        // cout << '\n';
        rep(i,0,b * b * (b + 1)){
            if(i % (b * b) == 0){
                int k = i / (b * b);
                rep(j,0,b + 1){
                    if(j == k) continue;
                    int d = (j - k) * (j - k);
                    M.d[i][j * b * b + d - 1] = 1;
                }
            } else {
                M.d[i][i - 1] = 1;
            }
        }
        M = M ^ n;
        // rep(i,0,b * b * (b + 1)){
        //     rep(j,0,b * b * (b + 1)) cout << M.d[i][j] << " ";
        //     cout << '\n';
        // }
        unsigned ans = 0;
        rep(i, 1, b + 1){
            rep(j, 0, b * b * (b + 1)) ans += f[j] * M.d[(i + 1) * b * b - 1][j];
        }
        cout << "Case " << T << ": " << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}