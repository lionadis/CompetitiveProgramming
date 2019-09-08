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
    int n, min_x = 1e9;
    cin >> n;
    if(n == 1){
        int x;
        cin >> x;
        return cout << x << '\n', 0;
    }
    bool pos = false, neg = false;
    ll sum = 0;
    rep(i,0,n){
        int x;
        cin >> x;
        if(x < 0) neg = true;
        else if(x > 0) pos = true;
        else pos = neg = true;
        min_x = min(abs(x), min_x);
        sum += abs(x);
    }

    if(neg && pos) cout << sum << '\n';
    else cout << sum - 2 * min_x << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}