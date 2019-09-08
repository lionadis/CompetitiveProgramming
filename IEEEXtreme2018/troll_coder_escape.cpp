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

int a[123], n;

void flip(int l, int  r){
	rep(i,l,r) a[i] = 1 - a[i];
}

int ask(string s){
	cout << s;
	rep(i,0,n) cout << " " << a[i];
	cout << '\n';
	if(s == "A") return 0;
	int x;
	cin >> x;
	return x;
}

void binary_search(int l, int r){
	while(l < r){
		int mid = (l + r + 1) / 2;
		flip(l, mid);
		int res = ask("Q");
		flip(l, mid);
		if(res == n - (mid - l) - 1) l = mid;
		else r = mid - 1;
	}
	flip(l, l + 1);
	ask("A");
}

int main() {
#ifdef LOCAL_DEFINE
//    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		memset(a, 0, sizeof a);
		int curr_ans = ask("Q");
		if(curr_ans == 0){
			fill(a, a + n, 1);
			ask("A");
			continue;
		}
		if(curr_ans == n){
			ask("A");
			continue;
		}
		if(curr_ans == n - 1){
			binary_search(0, n);
			break;
		}
		rep(i,0,n){
			a[i] = 1;
			int tmp = ask("Q");
			if(tmp == n - 1) binary_search(i + 1, n + 1);
				
			if(ask("Q") < curr_ans) a[i] = 0;
			else curr_ans++;
		}
		ask("A");
	}
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
