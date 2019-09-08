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

int m, p, n[123], nl;
string s;
template<class T, int N> struct Matrix{
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator * (const M& m) const{
        M a;
        rep(i,0,N) rep(j,0,N) rep(k,0,N) a.d[i][j] += d[i][k] * m.d[k][j], a.d[i][j] %= p;
        return a;
    }
};

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    freopen("nice.in","r",stdin);
    freopen("nice.out","w",stdout);
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    cin >> s >> m >> p;
    reverse(all(s));
    rep(i,0,sz(s)){
        n[nl++] = s[i] - '0';
    }
    Matrix<int, 1 << 5> M;
    rep(x, 0, 1 << m){
        rep(y, 0, 1 << m){
            int flag = 1;
            rep(k, 0, m - 1) {
                int a = ((x >> k) & 3), b = ((y >> k) & 3);
                if(a == b && (a == 3 || a == 0)) flag = 0;
            }
            M.d[x][y] = flag;
        }
    }
    n[0]--;
    int idx = 0;
    while(n[idx] < 0){
        n[idx++] += 10;
        n[idx]--;
    }
    if(n[nl - 1] == 0) nl--;
    Matrix<int, 1 << 5> m_ans;
    rep(i,0,1 << m) m_ans.d[i][i] = 1;
    while(nl){
        if(n[0] & 1) m_ans = M * m_ans;
        M = M * M;
        int carry = 0;
        for(int i=nl - 1; i >= 0; i--){
            int v = carry * 10 + n[i];
            n[i] = v / 2;
            carry = v % 2;
        }
        if(n[nl - 1] == 0) nl--;
    }
    ll ans = 0;
    rep(i,0,1 << m){
        rep(j,0,1 << m) ans += m_ans.d[i][j], ans %= p;
    }
    cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}