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

const int mod = (int) 1e9 + 7;

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n, best_buy = 0, best_sell = 1e9;
    ll ans = 1;
    cin >> n;
    set<int> s{best_buy, best_sell};
    while(n--){
        string op;
        int p;
        cin >> op >> p;
        if(op[2] == 'D') s.insert(p);
        else {
            if(p < best_buy || p > best_sell) ans = 0;
            if(p > best_buy && p < best_sell) ans *= 2, ans %= mod;
            auto it = s.find(p);
            best_buy = *prev(it);
            best_sell = *next(it);
            s.erase(it);
        }
    }
    int cnt = 0;
    for(auto it = s.find(best_buy); *it != best_sell; cnt++, it++);
    ans *= cnt, ans %= mod;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}