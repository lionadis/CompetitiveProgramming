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

vector<char> state[26][5123];

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	cout.precision(12);
	cout << fixed;
	string s;
	cin >> s;
	int n = sz(s);
	rep(i,0,n){
		rep(j,0,n){
			if(i == j) continue;
			int dist = -1;
			if(i < j) dist = j - i;
			if(i > j) dist = n - (i - j);
			state[s[i] - 'a'][dist].push_back(s[j]);
		}
	}
	double ans = 0;
	rep(i,0,26){
//		cout << (char)(i + 'a') << ':';
		int cnt = 0;
		rep(j,0,sz(s)){
			sort(all(state[i][j]));
			int curr_cnt = 0;
			rep(k,0,sz(state[i][j])){
				bool flag1 = true, flag2 = true;
				if(k > 0 && state[i][j][k] == state[i][j][k - 1]) flag1 = false;
				if(k < sz(state[i][j]) - 1 && state[i][j][k] == state[i][j][k + 1]) flag2 = false;
				curr_cnt += (flag1 && flag2);
			}
//			trav(c, state[i][j]) cout << c << ",";
//			cout << ":" << cnt;
//			cout << " ";
			cnt = max(cnt, curr_cnt);
		}
//		cout << "===>" << cnt << '\n'
//		cout << sz(state[i][1]) << '\n';
		if(sz(state[i][1])) ans += 1.0 * cnt;
	}
	cout << ans / sz(s) << '\n';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
