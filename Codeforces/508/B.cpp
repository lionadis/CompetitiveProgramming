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
    int n;
    cin >> n;
    if(n <= 2) return cout << "No\n", 0;
    int k = (n + 1) / 2;
    cout << "Yes\n";
    cout << "1 " << k << '\n';
    cout << n - 1;
    rep(i,1,n + 1) if(i != k) cout << " " << i;
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}