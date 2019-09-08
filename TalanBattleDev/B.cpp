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
	int n, ans = 0;
	cin >> n;
	for(int i=0;i<n;++i){
		string s;
		cin >> s;
		if(s.size() < 5) continue;
		if(s.size() > 7) continue;
		if(s[1] - s[0] != 1) continue;
		if(s[s.size() - 1] != 'a' && s[s.size() - 1] != 'e' && s[s.size() - 1] != 'e' && s[s.size() - 1] != 'i' && s[s.size() - 1] != 'u' && s[s.size() - 1] != 'y' && s[s.size() - 1] != 'o') continue;
		ans++;
	}
	cout << ans << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
