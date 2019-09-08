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
    freopen("group.in","r",stdin);
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n, m;
    cin >> n >> m;
    int mn = n - m, mx = 3 * (n - m - 1);
    if(m % 2) mx += 1 + 3 * (m - 1) / 2;
    else mx += 3 * m / 2;
    cout << mn <<  " " << mx << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}