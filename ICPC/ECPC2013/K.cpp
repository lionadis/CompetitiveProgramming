#include <bits/stdc++.h>

#define rep(i,a,b) for(int i=a;i<(b);++i)
#define F first
#define S second
#define sz(a) (a).size()

using namespace std;
const int maxn = 112;
int a[maxn], ans[maxn];


int main(){
    freopen("cubes.in", "r+",stdin);
    //freopen("test.in", "r+",stdin);
    int t, tc = 0;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        rep(i,0,n) cin >> a[i];
        sort(a, a + n);
        reverse(a, a + n);
        rep(i,0,n){
            if(i % 2 == 0) ans[n - i / 2 - 1] = a[i];
            else ans[i / 2] = a[i];
        }
        cout << "Case " <<++tc << ":\n";
        rep(i,0,n){
            cout << ans[i];
            if(i != n - 1) cout << " ";
        }
        if(t) cout << '\n';

    }
}
