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

const int maxn = 500123;
int d[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int t;
    cin >> t;
    while(t--){
        memset(d, 0, sizeof d);
        int n, s;
        cin >> n >> s;
        if((s < 2 && n > 1) || s > 9 * n){
            cout <<  "-1\n";
            continue;
        }
        if(n % 2 == 0){
            if(s % 2){
                cout <<  "-1\n";
                continue;
            }
            s /= 2;
            n /= 2;
            for(int i = 0;i < n; ++i){
                if(s <= 0) break;
                d[i] += min(9, s);
                s -= 9;
            }
            for(int i=0;i < n; ++i) cout << d[i];
            for(int i=n - 1;i >=0;--i) cout << d[i];
            cout << '\n';
        }
        else {
            int middle_digit = -1;
            if(s % 2) middle_digit = 1, s--;
            else middle_digit = 0;
            s /= 2;
            n /= 2;
            for(int i = 0;i < n; ++i){
                if(s <= 0) break;
                d[i] += min(9, s);
                s -= 9;
            }
            middle_digit += 2 * max(s, 0);
            for(int i=0;i < n; ++i) cout << d[i];
            cout << middle_digit;
            for(int i=n - 1;i >=0;--i) cout << d[i];
            cout << '\n';
        }
    }	
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
