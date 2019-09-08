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

const int mod = 1e9;
ll n, m;

template<class T, int N> struct Matrix{
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(M& a)const{
        M b;
        rep(i,0,1 << m) rep(k,0,1 << m) if(d[i][k]) rep(j,0,1 << m) b.d[i][j] += d[i][k] * a.d[k][j], b.d[i][j] %= mod;
        return b;
    }
    M operator^(ll p)const{
        M a, b(*this);
        rep(i,0,1 << m) a.d[i][i] = 1;
        while(p){
            if(p&1) a = a * b;
            b = b * b;
            p >>= 1;
        }
        return a;
    }
};

Matrix<ll, 256> M;

void dfs(int curr_mask, int target_mask, int idx){
    if(idx == m) {
        M.d[curr_mask][target_mask] += 1;
        return;
    }
    if(curr_mask & (1 << idx)) dfs(curr_mask, target_mask, idx + 1);
    else {
        dfs(curr_mask, target_mask, idx + 1);
        dfs(curr_mask, target_mask | (1 << idx), idx + 1);
        if(idx + 1 < m && !(curr_mask & (1 << (idx + 1)))) dfs(curr_mask, target_mask, idx + 2);
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    while(cin >> m >> n){
        rep(i,0,1 << m) rep(j,0,1 << m) M.d[i][j] = 0;
        rep(mask, 0, 1 << m) dfs(mask, 0, 0);
        M = M ^ n;
        // rep(i,0,1 << m){
        //     rep(j,0,1 << m) cout << M.d[i][j] << " ";
        //     cout << '\n';
        // }
        cout << M.d[0][0] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}