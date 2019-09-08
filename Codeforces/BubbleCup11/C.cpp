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

const int maxn = 200123;
int a[maxn], b[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n, m;
    cin >> n >> m;
    m--;
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) cin >> b[i];
    int score = a[m] + b[0];
    rep(i,1,n){
        if(!m) break;
        if(a[m - 1] + b[i] <= score) m--;
    }
    cout << m + 1 << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}