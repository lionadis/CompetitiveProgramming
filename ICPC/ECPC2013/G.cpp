#include <bits/stdc++.h>

#define rep(i,a,b) for(int i=a;i<(b);++i)
#define F first
#define S second
#define sz(a) (a).size()

using namespace std;

int main(){
    freopen("jenga.in", "r+",stdin);
    int t, tc = 0;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << "Case " << ++tc << ": " << (n % 3 ? "Bakkar\n" : "Wahdan\n");
    }
}
