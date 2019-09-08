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

const int maxn = 512;
const int mod = 998244353;
int a[maxn];
unordered_map<ll, int> cnt;

ll nth_sqrt(ll x, int n){
    ll l = 0, r = (ll)pow(2e18, 1.0 / n);
    while(l < r){
        ll mid = (l + r + 1) / 2;
        ll res = 1;
        rep(i,0,n) res *= mid;
        if(res <= x) l = mid;
        else r = mid - 1;
    }
    return l;
}

bool check(ll x){
    for(int i = 4;i >= 2;--i){
        ll res = nth_sqrt(x, i), res1 = 1;
        rep(j,0,i) res1 *= res;
        if(res1 == x){
            cnt[res] += i;
            return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n;
    cin >> n;
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) cout << a[i] << " ";
    cout << '\n';
    rep(i,0,n){
        rep(j,0,n){
            if(i != j){
                ll g = __gcd(a[i], a[j]);
                if(g != 1) a[i] /= g, a[j] /= g, check(g), check(g);
            }
        }
    }
    rep(i,0,n) cout << a[i] << " ";
    cout << '\n';
    rep(i,0,n){
        if(a[i] != 1 && check(a[i])) a[i] = 1;
    }
    rep(i,0,n) cout << a[i] << " ";
    cout << '\n';
    ll ans = 1;
    trav(p, cnt) ans *= p.S + 1, ans %= mod;
    rep(i,0,n) if(a[i] != 1) ans *= 4, ans %= mod;
    cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}