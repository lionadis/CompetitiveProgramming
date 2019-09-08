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

const int maxn = 100123;
int a[maxn], b[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n;
    cin >> n;
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) cin >> b[i];
    sort(a, a + n, greater<int>());
    sort(b, b + n, greater<int>());
    int idx_a = 0, idx_b = 0, turn = 2 * n;
    ll sum_a = 0, sum_b = 0;
    while(turn --){
        if(turn & 1){
            if(b[idx_b] > a[idx_a]) idx_b++;
            else sum_a += a[idx_a++];
        }
        else {
            if(b[idx_b] > a[idx_a]) sum_b += b[idx_b++];
            else idx_a++;
        }
    }
    cout << sum_a - sum_b << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}