#include <bits/stdc++.h>

#define rep(i,a,b) for(int i=a;i<(b);++i)
#define F first
#define S second
#define trav(a,x) for(auto & a : x)
#define sz(a) (a).size()
#define all(a) (a).begin(), (a).end()
using namespace std;

vector<vector<int> > G;

int main(){
    freopen("mahdi.in", "rt",stdin);
    int t;
    cin >> t;
    int tc = 0;
    while(t--){
        G.clear();G.resize(30);
        char c;
        int len, mul, add;
        cin >> c >> len >> mul >> add;
        long long curr = c - 'a';
        G[curr].push_back(0);
        rep(i,1,len){
            curr = curr * mul + 1LL * i * add;
            curr %= 26;
            G[curr].push_back(i);
        }
        int q;
        cin >> q;
        cout << "Case " << ++tc << ":\n";
        while(q--){
            bool ans = true;
            cin >> c >> len >> mul >> add;
            curr = c - 'a';
            int idx = 0;
            rep(i,0,len){
                int p = upper_bound(all(G[curr]), idx) - G[curr].begin();
                if(p == sz(G[curr])){
                    ans = false;
                    break;
                }
                idx = G[curr][p];
                curr = curr * mul + (i + 1) * add;
                curr %= 26;
            }
            cout << (ans ? "BRAVO\n" : "REPEAT\n");
        }
    }
}
