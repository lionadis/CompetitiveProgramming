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

const int inf = 1e9 + 123;
const int maxn = 200123;
int n;
pair<pii, pii> a[maxn], t[2 * maxn];

pair<pii, pii> f(pair<pii, pii> a, pair<pii, pii> b){
    return {{max(a.F.F, b.F.F), max(a.F.S, b.F.S)}, {min(a.S.F, b.S.F), min(a.S.S, b.S.S)}};
}

void build(){
    for(int i = n - 1; i > 0; --i) t[i] = f(t[i << 1], t[i << 1 | 1]);
}

pair<pii, pii> q(int l, int r){
    pair<pii, pii> res = {{-inf, -inf}, {inf, inf}};
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
        if(l & 1) res = f(res, t[l++]);
        if(r & 1) res = f(res, t[--r]);
    }
    return res;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    cin >> n;
    rep(i,0,n) cin >> a[i].F.F >> a[i].F.S >> a[i].S.F >> a[i].S.S;
    rep(i,n,2 * n) t[i] = a[i - n];
    build();
    rep(i,0,n){
        pair<pii, pii> res;
        if(i == 0) res = q(1, n);
        else if(i == n - 1) res = q(0, n - 1);
        else res = f(q(0, i), q(i + 1, n));
        if(res.F.F <= res.S.F && res.F.S <= res.S.S) return cout << res.F.F << " " << res.F.S << '\n', 0;
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}