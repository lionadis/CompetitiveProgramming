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
    int n, a[2][4];
    cin >> n;
    rep(i,0,3) cin >> a[0][i] >> a[1][i];
    if((a[0][1] < a[0][0]) && (a[0][0] < a[0][2]) 
        || (a[0][1] > a[0][0]) && (a[0][0] > a[0][2]) 
        || (a[1][1] < a[1][0]) && (a[1][0] < a[1][2]) 
        || (a[1][1] > a[1][0]) && (a[1][0] > a[1][2])) cout << "NO\n";
    else cout << "YES\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}