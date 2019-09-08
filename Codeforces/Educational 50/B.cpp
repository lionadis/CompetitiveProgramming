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

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int q;
    cin >> q;
    while(q--){
        ll n, m, k, ans = 0;
        cin >> n >> m >> k;
        ll d = min(n, m), s = max(n, m) - min(n, m);
        ans = k, k -= d;
        if(k < s){
            cout << "-1\n";
            continue;
        }
        if((k & 1) && !(s & 1)) ans -= 2;
        if(!(k & 1) && (s & 1)) ans -= 1;
        if((k & 1) && (s & 1)) ans -= 1;
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}