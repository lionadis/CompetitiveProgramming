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

const int maxn = 200;
string s[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n, m;
    cin >> n >> m;
    rep(i,0,n) cin >> s[i];
    int start_x = -1, end_x = -1, start_y = -1, end_y = -1;
    
    rep(j,0,m){
        if(start_x != -1 && end_x != -1) break;
        rep(i,0,n){
            if(s[i][j] == 'B'){
                if(start_x == -1) start_x = i;
                else end_x = i;
            }
        }
    }

    rep(i,0,n){
        if(start_y != -1 && end_y != -1) break;
        rep(j,0,m){
            if(s[i][j] == 'B'){
                if(start_y == -1) start_y = j;
                else end_y = j;
            }
        }
    }

    if(end_x == -1) end_x = start_x;
    if(end_y == -1) end_y = start_y;

    cout << (start_x + end_x) / 2 + 1 << " " << (start_y + end_y) / 2  + 1 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}