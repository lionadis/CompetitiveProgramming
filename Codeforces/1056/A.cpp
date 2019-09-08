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
	bitset<110> ans;
	ans.set();
	cin >> n;
	rep(i,0,n){
		int r;
		cin >> r;
		bitset<110> tmp;
		tmp.reset();
		rep(j,0,r){
			int x;
			cin >> x;
			tmp[x] = 1;
		}
		ans &= tmp;
	}
	rep(i,0,110) if(ans[i]) cout << i << " ";
	cout << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
