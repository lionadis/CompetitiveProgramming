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

vector<long> divs, ans;

int main() {
#ifdef LOCAL_DEFINE
    freopen("test.in","r",stdin);
#else
    cin.sync_with_stdio(0); cin.tie(0);
#endif
	int n;
	cin >> n;
	rep(i,1,sqrt(n) + 1){
		if(i > n / i) break;
		if(n % i == 0){
			divs.push_back(i);
			if(n / i != i) divs.push_back(n / i);
		}
	}
	trav(d, divs){
		ll k = n / d;
		ans.push_back(k + k * (k - 1) * d / 2);
	}
	sort(all(ans));
	trav(x, ans) cout << x << ' ';
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * (double) clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
