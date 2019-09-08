/*
    Editorial : Straight forward when you understand the problem, the hacker want to divide the graph into the maximal number of subsets, such
    that each subset covers the whole graph
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int N = 17;
int a[1 << N], f[1 << N], dp[1 << N];

int solve(int mask){
    if(mask == 0) return 0;
    int &ans = dp[mask];
    if(~ans) return ans;
    for(int i=mask;i;i=(i-1)&mask){
        if(f[i]){
            ans = max(ans, 1 + solve(mask&(~i)));
        }
    }
    return ans;
}

int main(){
#ifdef LOCAL_DEFINE
    freopen("test.in", "r", stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
#endif
    int n;
    int T = 1;
    while(cin >> n, n){
        memset(a, 0, sizeof a);
        memset(dp, -1, sizeof dp);
        memset(f, 0, sizeof f);
        rep(i,0,n){
            int x;
            cin >> x;
            a[i] |= 1 << i;
            rep(j,0,x){
                int u;
                cin >> u;
                a[i] |= 1 << u;
            }
        }
        int all = (1 << n) - 1;
        rep(mask,1,all + 1){
            int cover = 0;
            rep(i,0,n){
                if(mask & 1 << i) cover |= a[i];
            }
            if(cover == all) f[mask] = 1;
        }
        cout << "Case " << T++ << ": " << solve(all) << '\n';
    }

#ifdef LOCAL_DEFINE
    cout <<"\nTime elapsed: "<<(1000 * clock() / CLOCKS_PER_SEC)<<"ms\n";
 #endif
}