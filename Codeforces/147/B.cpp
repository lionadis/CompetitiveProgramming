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

const int maxn = 312;
int n, m;
ll a[maxn][maxn], cnt[maxn][maxn];

void upd(int &a, int b){
    if(a < b) a = b;
}

template<class T, int N> struct Matrix{
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(M &a){
        M b;
        rep(i,0,n) rep(j,0,n) b.d[i][j] = -1e9;
        rep(i,0,n) rep(j,0,n) rep(k,0,n) upd(b.d[i][j], d[i][k] + a.d[k][j]);
        return b;
    }
    M operator^(int p){
        M a(*this), b(*this);
        rep(i,0,n) rep(j,0,n) if(i != j) a.d[i][j] = -1e9;
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
    cin >> n >> m;
    Matrix<ll, 300> M, M_ans;
    rep(i,0,n) rep(j,0,n) if(i != j) M.d[i][j] =  M_ans.d[i][j] = -1e9;
    rep(i,0,m){
        int u, v, c1, c2;
        cin >> u >> v >> c1 >> c2;
        --u, --v;
        M.d[u][v] = c1;
        M.d[v][u] = c2;
    }
    int ans = 0;
    for(int k=9;~k;k--){
        Matrix<ll, 300> M1(M);
        rep(j,0,k) M1 = M1 * M1;
        M1 = M1 * M_ans;
        bool flag = false;
        rep(i,0,n) flag |= (M1.d[i][i] > 0);
        if(!flag) ans |= (1 << k), M_ans = M1;
    }
    cout << ans << '\n';
    cout << (ans + 1 > n ? 0 : ans + 1) << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}