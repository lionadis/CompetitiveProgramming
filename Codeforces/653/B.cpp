#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int n, q, ans;
string s;
vector<string> all_strings;
unordered_map<string, string> m;

void dfs(int pos){
	if(pos == n){
		all_strings.push_back(s);
		return;
	}
	rep(i,0,6){
		s.push_back('a' + i);
		dfs(pos + 1);
		s.pop_back();
	}
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	cin >> n >> q;
	rep(i,0,q){
		string a, b;
		cin >> a >> b;
		m[a] = b;
	}
	dfs(0);
	for(auto &s:all_strings){
		while(sz(s) != 1){
			string pref = s.substr(0, 2);
			if(m.find(pref) == m.end()) break;			
			s = m[pref] + s.substr(2);
		}
		if (s == "a") ans++;
	}
	cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
