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

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
    int n;
    cin >> n;
    map<string, int> m;
    m["xrtp"] = 0;
    m["pmr"] = 1;
    m["yep"] = 2;
    m["yjtrr"] = 3;
    m["gpit"] = 4;
    m["gobr"] = 5;
    m["doc"] = 6;
    m["drbrm"] = 7;
    m["rohjy"] = 8;
    m["momr"] = 9;
    string s;
    getline(cin, s);
    string first = "";
    int cnt = 0;
    rep(i,0,n){
        getline(cin, s);
        stringstream ss(s);
        while(ss >> s){
			cnt++;
			if(first == "") first = s;
			int x;
			cin >> x;
			cout << x;
		}
    }
    rep(i,0,cnt) cout << m[first];
    
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
