#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

bool a[123];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	a['a'] = a['e'] = a['i'] = a['o'] = a['u'] = 1;
	string s, t;
	cin >> s >> t;
	if(sz(s) != sz(t)) return cout << "No\n", 0;
	rep(i,0,sz(s)){
		if(a[s[i]] != a[t[i]]) return cout << "No\n", 0;
	}
	cout << "Yes\n";
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
