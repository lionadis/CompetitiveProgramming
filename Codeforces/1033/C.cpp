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

const int maxn = 100213;
int a[maxn], dp[2][maxn], n;

int solve(int idx, int p){
    int &res = dp[p][idx];
    if(res != -1){
        return res;
    }
    if(p == 0){
        res = 1;
        int k = a[idx];
        while(idx + k < n || idx - k >= 0){
            if(idx + k < n && a[idx + k] > a[idx]) res = min(res, solve(idx + k, 1));
            if(idx - k >= 0 && a[idx - k] > a[idx]) res = min(res, solve(idx - k, 1));
            k += a[idx];
        }
        
    }
    if(p == 1){
        res = 0;
        int k = a[idx];
        while(idx + k < n || idx - k >= 0){
            if(idx + k < n && a[idx + k] > a[idx]) res = max(res, solve(idx + k, 0));
            if(idx - k >= 0 && a[idx - k] > a[idx]) res = max(res, solve(idx - k, 0));
            k += a[idx];
        }
    } 
    return res;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    memset(dp, -1, sizeof dp);
    cin >> n;
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) cout << (solve(i, 0) == 0 ? "A" : "B");
    cout << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}