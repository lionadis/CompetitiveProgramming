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
int ans[maxn];
set<pii> s;

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n, m, d;
    cin >> n >> m >> d;
    rep(i,0,n){
        int x;
        cin >> x;
        s.insert({x, i});
    }
    int day = 0;
    while(!s.empty()){
        day++;
        for(auto it = s.begin(); it != s.end();){
            ans[it->S] = day;
            auto it2 = it;
            it = s.lower_bound({it->F + d + 1, -1e9});
            s.erase(it2);
        }
    }
    cout << day << '\n';
    rep(i,0,n) cout << ans[i] << ' ';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}